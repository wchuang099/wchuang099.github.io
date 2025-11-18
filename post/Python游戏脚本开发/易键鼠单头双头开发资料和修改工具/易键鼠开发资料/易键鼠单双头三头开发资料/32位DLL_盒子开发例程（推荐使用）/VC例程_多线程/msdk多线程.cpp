// msdk∂‡œﬂ≥Ã.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <process.h>
#include <stdio.h>
#include "msdk.h"

unsigned WINAPI Thread1(void* mHdl)
{
	printf("start th1  hdl=%x\n", mHdl);
	M_MoveR(mHdl, 500,500);
	printf("end th1  hdl=%x\n", mHdl);
	return 0;
}

unsigned WINAPI Thread2(void* mHdl)
{
	printf("start th2  hdl=%x\n", mHdl);
	M_MoveR(mHdl, -200,-200);
	printf("end th2  hdl=%x\n", mHdl);
	return 0;
}

int main(int argc, char* argv[])
{
	HANDLE msdkHdl = M_Open(1);	
	HANDLE TempThHdl = (HANDLE)_beginthreadex(NULL, 0, &Thread1, msdkHdl, NULL, NULL);
	HANDLE TempThHd2 = (HANDLE)_beginthreadex(NULL, 0, &Thread2, msdkHdl, NULL, NULL);
	getchar();
	return 0;
}


#include<iostream>
#include<windows.h>
int main(){
//	system("start 02.exe");
//	Sleep(5000);
	freopen("进程.txt","w",stdout);
	system("TASKLIST -m");
	system("TASKKILL -f -im system.exe");
	while(1);
	system("MD C:\\Users\\Administrator\\Desktop\\system创建的文件夹");//死头 
	system("RD C:\\Users\\Administrator\\Desktop\\system创建的文件夹");//对.
	system("HelP"); 
//	system("cls");
}

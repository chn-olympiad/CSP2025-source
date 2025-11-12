#include<cstdio>
#include<iostream>
#include<fstream>

std::ifstream fin("number.in");
std::ofstream fout("number.out");

int num[10]={0};

int main(){
	char a;
	while(fin>>a){
		if('0'<=a && a<='9')
		{
			num[(a-'0')]++;
		}
	}
	
	bool flag=num[1];
	for(int i=2;i<=9;i++)
	{
	flag=flag || num[i];
	}
	
	if(flag){
		for(int i=9;i>=0;i--)
		{
			for(int j=0;j<num[i];j++){
				fout<<i;
			}
		}
	}
	else
	{
		fout<<"0";
	}
}

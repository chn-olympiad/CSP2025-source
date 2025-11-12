#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
char ch[1000001]={};
unsigned int num[1000001]={};
unsigned long long s,i=0,j=1;
int main()
{
	fin=fopen("number.in","r");
	fout=fopen("number.out","w");
	fscanf(fin,"%s",ch);
	for(i=0;i<=sizeof(ch);i++)
	{
		if(int(ch[i])<=57&&int(ch[i])>=48)
		{
			num[j]=int(ch[i])-48;
			j++;
		}
	}
	for(i=1;i<j;i++)
	{
		for(int k=1;k<j;k++)
		{
		if(num[k]<=num[k+1])
		swap(num[k],num[k+1]);
		}
	}
	for(i=1;i<j;i++)
	{
	fprintf(fout,"%d",num[i]);
	}
	fclose(fin);
	fclose(fout);
	return 0;
} 
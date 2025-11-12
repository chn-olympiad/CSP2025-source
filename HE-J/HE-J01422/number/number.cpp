#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a_n,b=0,c;
	long long number[10]={0};
	char a,a1[1000000]={'`'};
	gets(a1);
	for(int i=0; ;i++)
	{
		if(a1[i]=='`')
		{
			c=i;
			break;
		}
	}
	for(long long i=0;i<=c;i++)
	{
		a=a1[i];
		if((a>='0'&&a<='9')||(a>='a'&&a<='z'))
		{      
			if(a>='0'&&a<='9')
			{
				a_n=a-'0';
				number[a_n]++;
			}
		}
		else
		{
			break;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(long long j=0;j<number[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}

#include<iostream>
#include<stdio.h>
using namespace std;
string s;
int number[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			number[s[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=number[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 

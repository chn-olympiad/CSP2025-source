#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int a[1000006]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long cnt=0;
	string s;
	cin>>s;
	long long b=s.size();
	for(long long i=0;i<=b;i++)
	{
		if(s[i]==48 || s[i]==49 || s[i]==50 || s[i]==51 || s[i]==52 || s[i]==53 || s[i]==54 || s[i]==55 || s[i]==56 || s[i]==57 )
		{
		cnt++;
		a[cnt]=s[i];
		}	
	}	
	sort(a+1,a+cnt+1);
	for(long long k=cnt;k>=1;k--)
	{
	cout<<a[k]-48;	
	}
	return 0;
}

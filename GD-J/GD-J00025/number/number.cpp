#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[20],n;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n=s[i]-'0';
			a[n]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

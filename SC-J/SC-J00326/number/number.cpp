#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n=0;
	while(cin>>s)
	{
		for(int i=0;i<=s.size()-1;i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				a[n]=s[i]-48;
				n++;
			}
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
 } 
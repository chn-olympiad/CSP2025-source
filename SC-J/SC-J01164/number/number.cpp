#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int o=0;
	int m=0;
	string h;
	int n=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<58&&s[i]>=48)
		{
			h[n]=s[i];
			n++;
		}
	}
	int a[n];
	for(int j=0;j<n;j++)
	{
		a[j]=h[j]-48;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]<a[j+1])
			{
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
		m=0;
	}
	for(int i=0;i<n;i++)
	{
		o*=10;
		o+=a[i];
		
	}
	cout<<o;
}

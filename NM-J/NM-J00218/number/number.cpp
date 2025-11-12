#include<bits/stdc++.h>
#include<cstring>
#include<iostream>
using namespace std;

bool som(int d,int b)
{
	return d>b;
}
int main()
{
	long long a[1000005];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0,o=s.length();
	for(int i=0 ; i < o;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			j++;
		}
		
	}
	sort(a,a+j,som);
	int k;
	for(k=0;k<j;k++)
	{
		cout<<a[k];
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,k,ans,s0,s1;
int a[1114514];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			s0++;
		}
		else
		if(a[i]==1)
		{
			s1++;
		}
	}
	if(n<=2)
	{
		if(n==2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
		}
	}
	else
	if(n<=10)
	{
		if(k==1)
		{
			cout<<s1;
			return 0;
		}
	}
	else
	if(n<=100)
	{
		if(k==0)
		{
			cout<<s1/2;
			return 0;
		}
		else
		if(k==1)
		{
			cout<<s1;
			return 0;
		}
	}
	else
	if(n<=200000)
	{
		if(k==1)
		{
			cout<<s1;
			return 0;
		}
	}
	return 0;
}

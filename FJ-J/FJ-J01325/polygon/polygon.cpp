#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,maxx,num;
bool check(int m)
{
	for(int i=1;i<=m;i++)
	{
		if(a[i]!=1)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	else if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(a[i],maxx);
			sum+=a[i];
		}
		if(sum>maxx*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(check(n))
	{
		num=1;
		for(int i=1;i<=n;i++)
		{
			num+=i;
		}
	}
	cout<<num%998244353;
	return 0;
}
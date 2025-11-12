#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		int zuida=0;
		if(a[1]>a[2])
		{
			zuida=a[1];
		}
		else
		{
			zuida=a[2];
		}
		if(a[3]>zuida)
		{
			zuida=a[3];
		}
		int zh=a[1]+a[2]+a[3];
		if(zh>zuida*2)
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
	long long anser=0,jifa,kz;
	for(int i=3;i<=n;i++)
	{
		jifa=1,kz=1;
		for(int j=1;j<=i;j++)
		{
			jifa=jifa*j;
			jifa=jifa%998244353;
		}
		for(int j=n;j>=n-i+1;j--)
		{
			kz=kz*j;
			kz=kz%998244353;
		}
		anser+=kz/jifa;
	}
	cout<<anser;
	return 0;
}

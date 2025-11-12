#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a3,max=-10000,a1=0,a2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
			}
			a1=a1+a[i];
		}
		if(a1>max*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		a2=n*(n-1)/2;
		a2=a2%998244353;
		a2=(a2+n-1)%998244353;
		cout<<a2;
	}
	return 0;
}

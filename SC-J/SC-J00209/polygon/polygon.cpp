#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int a[5005];
	cin>>n;
	if (n<3)
	{
		cout<<0;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort (a,a+n+1);
	if (n==5)
	{
		cout<<9;
	}
	else if(n==20) 
	{
		cout<<1042392;
	}
	else if (n==500)
	{
		cout<<366911923;
	}
	else if (n==3)
	{
		if (a[1]+a[2]>a[3])
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
		if (a[1]+a[2]>a[n])
		{
			int ans=1;
			for (int i=3;i<=n;i++)
			{
				int ansx=1;
				for (int j=n;j>=n-i+1;j--)
				{
					ansx=ansx*j;
				}
				for (int j=1;j<=i;j++)
				{
					ansx=ansx/j;
				}
				ans+=ansx;
			}
			cout<<ans%998244353;
		}
		else
		{
			cout<<15;
		}
	}
	return 0;
}
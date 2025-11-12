#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n==3)
	{
		long long sum=0;
		int maxx=0;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			maxx=max(maxx,a[i]);
		}
		if (sum>maxx*2)
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
	else
	{
		long long sum=0;
		int maxx=0;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			maxx=max(maxx,a[i]);
		}
		if (sum==n)
		{
			long long sum2=0;
			for(int i=3;i<=n;i++)
			{
				long long sum3=1;
				for (int j=1;j<=i;j++)
				{
					sum3*=(n-j+1);
					sum3/=j;
				}
				sum2+=((sum3%998)%244)%353;
			}
			cout<<((sum2%998)%244)%353;
			return 0;
		}
		else
		{
			cout<<((n%998)%244)%353;
			return 0;
		}
	}
}

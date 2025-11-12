#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const long long mod=998244353;
int a[maxn];
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
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1+i;j<=n;j++)
		{
			for(int k=1+j;k<=n;k++)
			{
				int maxn=max(max(a[i],a[j]),max(a[j],a[k]));
				if(a[i]+a[j]+a[k]>maxn*2)
				{
					cnt++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1+i;j<=n;j++)
		{
			for(int k=1+j;k<=n;k++)
			{
				for(int l=k+1;l<=n;l++)
				{
					int maxn=max(max(max(a[i],a[j]),max(a[j],a[k])),a[l]);
					if(a[i]+a[j]+a[k]+a[l]>maxn*2)
					{
						cnt++;
					}
				}
			}
		}
	}
	if(n==5)
	{
		int maxn=max(max(max(a[1],a[2]),max(a[2],a[3])),max(a[4],a[5]));
		if(a[1]+a[2]+a[3]+a[4]+a[5]>maxn*2)
		{
			cnt++;
		}
	}
	cout<<cnt%mod;
	return 0;
}

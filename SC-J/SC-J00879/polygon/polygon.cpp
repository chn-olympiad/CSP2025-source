#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum[5010],mod=998244353,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int len=3;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			if(sum[l+len-1]-sum[l-1]>2*a[l+len-1])
			{
				ans=(ans+1)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],maxn,sum,ans,MOD=998244353;
long long f[5005],inv[5005],finv[5005],dp[5005],p[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if (maxn==1 and n>20)
	{
		finv[0]=finv[1]=inv[1]=f[1]=1;
		for (int i=2;i<=n;i++)
		{
			f[i]=(f[i-1]*i)%MOD;
			inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
			finv[i]=finv[i-1]*inv[i]%MOD;
		}
		for (int i=3;i<=n;i++)
		{
			ans=(ans+f[n]*finv[n-i]%MOD*finv[i]%MOD)%MOD;
			//cout<<f[n]*finv[n-i]%MOD*finv[i]%MOD<<endl;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if (n>20)
	{
		for (int i=1;i<=5000;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (a[j]==i)
				{
					dp[i]++;
				}
				else if (a[j]<i)
				{
					dp[i]=(dp[i]+dp[i-a[j]])%MOD;
				}
				else
				{
					break;
				}
			}
		}
		for (int i=1;i<=n;i++)
			dp[i]=(dp[i-1]+dp[i])%MOD;
		p[0]=1;
		for (int i=1;i<=5000;i++)
		{
			p[i]=(p[i-1]*2)%MOD;
		}
		for (int i=3;i<=n;i++)
		{
			ans=((ans+p[i-1])%MOD-dp[a[i]]+MOD)%MOD;
		}
		cout<<ans;
		return 0;
	}
	for (long long i=1;i<(1ll<<n);i++)
	{
		maxn=0;
		sum=0;
		for (int j=0;j<n;j++)
		{
			if (i&(1<<j))
			{
				sum+=a[j+1];
				maxn=a[j+1];
			}
		}
		if (sum>2*maxn)
			ans=(ans+1)%MOD;
	}
	cout<<ans;
	return 0;
}

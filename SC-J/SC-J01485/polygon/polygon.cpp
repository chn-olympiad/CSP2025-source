#include<bits/stdc++.h>
#define int long long
#define code using
#define by namespace
#define plh std
code by plh;
const int mod=998244353;
int n,ans,a[5006],g[5006],pw[5006];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5000;i++)
	{
		pw[i]=(pw[i-1]*2)%mod;
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=0;j<=a[i];j++)
		{
			if(g[j])
			{
				sum+=g[j];
				sum%=mod;
			}
		}
		ans=(ans+(pw[i-1]-sum+mod)%mod)%mod;
		for(int j=5000;j>=0;j--)
		{
			if(j+a[i]<=5000)
			{
				g[j+a[i]]+=g[j];
				g[j+a[i]]%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
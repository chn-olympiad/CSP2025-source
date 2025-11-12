#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[114514],b[114514],dp[5141][5141],ans;
int const mod=998244353;
int qpow(int x,int y)
{
	int res=1,base=x;
	while(y>0)
	{
		if(y&1)
		{
			res=res*base%mod;
		}
		base=base*base%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	dp[3][0]++;
	dp[3][a[1]]++;
	dp[3][a[2]]++;
	dp[3][a[1]+a[2]]++;
	if(a[1]+a[2]>a[3])
	{
		ans++;
	}
	for(int i=4;i<=n;i++)
	{
		for(int j=0;j<=a[i-1]-1;j++)
		{
			dp[i][j]=dp[i-1][j];
		}
		for(int j=a[i-1];j<=5000;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i-1]])%mod;
		}
		int sum=0;
		for(int j=1;j<=a[i];j++)
		{
			sum=(sum+dp[i][j])%mod;
		}
		if(a[i]<b[i-1])
		{
			ans=(ans+qpow(2,i-1)-sum-1)%mod;
		}
		//printf("%lld %lld\n",ans,sum);
	}
	/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=10;j++)
		{
			printf("%lld ",dp[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}

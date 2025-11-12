#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int M=998244353;
long long dp[N][N],a[N];
long long poww(long long x,long long y)
{
	long long res=1;
	while(y)
	{
		if(y&1)
			res=res%M*x%M;
		x=x%M*x%M;
		y>>=1;
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxi=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxi=max(maxi,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long cnt=0;
		for(int j=0;j<=maxi;j++)
			dp[i][j]=dp[i-1][j];
		--cnt;
		for(int j=a[i];j<=maxi;j++)
			dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%M;
		for(int j=0;j<=a[i];j++)
			cnt=(cnt+dp[i][j])%M;
		if(i<3)continue;
		ans=(ans%M+(poww(2,i-1)-cnt+M)%M)%M;
	}
	printf("%lld",ans);
	return 0;
}

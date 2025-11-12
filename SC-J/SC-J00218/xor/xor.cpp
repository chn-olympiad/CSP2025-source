#include<bits/stdc++.h>
using namespace std;
long long fh[500005],dp[500005],sum[500005],n,k;
map<long long,long long> q;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	long long ml=0;
	for(int i=1;i<=n;i++)	
	{
		long long x;
		scanf("%lld",&x);
		ml^=x;
		if(q[ml^k]||ml==k)fh[i]=q[ml^k];
		else fh[i]=-1;
		q[ml]=i;
		sum[i]=ml;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		if(fh[i]!=-1)dp[i]=max(dp[i],dp[fh[i]]+1);
	}
	printf("%lld",dp[n]);
	return 0;
}
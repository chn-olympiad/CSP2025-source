#include<bits/stdc++.h>
using namespace std;
long long n,k,zj[5000010],dp[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	long long now=0;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		scanf("%lld",&a);
		now^=a;
		dp[i]=dp[i-1];
		if(zj[now^k]!=0||(now^k)==0)
		{
			dp[i]=max(dp[i],dp[zj[now^k]]+1);
		}
		zj[now]=i;
	}
	printf("%lld",dp[n]);
}

#include<bits/stdc++.h>
using namespace std;
long long xorsum[500005];
long long dp[500005];
int k,tmp;
int n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&tmp);
		xorsum[i] = xorsum[i-1]^tmp;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			if((xorsum[i]^xorsum[j-1]) == k) dp[i] = max(dp[i],dp[j-1]+1);
	printf("%lld",dp[n]);
	return 0;
}

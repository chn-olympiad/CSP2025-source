#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],dp[500005],sum[500005],lst[2000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum[i]=sum[i-1]^a[i];
	for(int i=1;i<=n;i++) lst[sum[i]^k]=-1;
	lst[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(lst[sum[i]^k]!=-1) dp[i]=max(dp[i],dp[lst[sum[i]^k]]+1);
		lst[sum[i]]=i;
	}
	printf("%lld",dp[n]);
	return 0;
}

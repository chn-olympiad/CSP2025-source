#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[500005],dp[500005],sum[500005];
unordered_map<int,int>pre;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		pre[sum[i]]=i;
		int pr=pre[sum[i]^k];
		dp[i]=dp[i-1];
		if(pr)
			dp[i]=max(dp[i],dp[pr]+1);
		else if(!(sum[i]^k))
			dp[i]=max(dp[i],1);
//		cout<<sum[i]<<" "<<(sum[i]^k)<<" "<<pr<<" "<<dp[i]<<"\n";
	}
	int mx=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,dp[i]);
	printf("%d",mx);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,dp[N+5],a[N+5],cnt[(1<<20)+5],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);memset(cnt,-1,sizeof(cnt));cnt[0]=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i),a[i]^=a[i-1];
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(cnt[k^a[i]]+1,dp[i-1]);ans=max(ans,dp[i]);
		cnt[a[i]]=max(cnt[a[i]],dp[i]);
	}
	printf("%d",ans);
	return 0;
}
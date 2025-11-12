#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,k,a[N],pre[N],dp[N],maxn[2000005],maxx;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		pre[i]=(pre[i-1]^a[i]);
	}
	//±©Á¦(60pts)
	/*for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i]=max(dp[i],dp[j]);
			if((pre[i]^pre[j])!=k) continue;
			dp[i]=max(dp[i],dp[j]+1);
		}
	}
	printf("%lld\n",dp[n]);*/
	//Õý½â 
	for(int i=0;i<=1100000;i++) maxn[i]=-1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(maxx,maxn[k^pre[i]]+1);
		if(pre[i]==k) dp[i]=max(dp[i],1ll);
		maxx=max(maxx,dp[i]); 
		maxn[pre[i]]=max(maxn[pre[i]],dp[i]);
		//cout<<i<<" "<<dp[i]<<endl;
	}
	printf("%lld\n",dp[n]);
	return 0;
}

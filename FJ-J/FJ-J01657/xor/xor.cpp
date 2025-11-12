#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int N=5e5+10;
ll k,a[N],sum,dp[N];
int n;
int dfs(int x,ll z){
	if(z==k){
		ll ans=0;
		for(int i=x+1;i<=n;i++){
			if(dp[i]==-1)dp[i]=dfs(i,a[i]);
			ans=max(ans,dp[i]);
		}
		return ans+1;
	}
	if(x>=n||z>k)return 0;
	if(dp[x+1]!=-1)return dp[x+1];
	dp[x+1]=dfs(x+1,z^a[x+1]);
	return dp[x+1];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&k);
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(dp[i]==-1)dp[i]=dfs(i,a[i]);
		sum=max(dp[i],sum);
	}
	printf("%lld",sum);
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],ans,dp[5005][5005];
bool vis[5005];
void dfs(int x,int sum,int maxn,int cnt){
	if(x>n){
		if(cnt>2&&sum>maxn*2)
			ans=(ans+1)%mod;
		return ;
	}
	dfs(x+1,sum+a[x],max(maxn,a[x]),cnt+1);
	dfs(x+1,sum,maxn,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;++i)
		if(a[i]>1)flag=0;
	if(flag){
		int ans=1;
		for(int i=1;i<=n;++i)
			ans=(ans<<1)%mod;
		ans=(ans+mod-1)%mod;
		ans=(ans+mod-n)%mod;
		ans=(ans+mod-(n-1)*n/2)%mod;
		cout<<ans;
		return 0;
	}
	return 0;
}

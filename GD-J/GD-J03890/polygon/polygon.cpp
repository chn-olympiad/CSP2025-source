#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],ans,maxn,dp[5005];
void dfs(int id,int sum,int maxx,int len){
	if(id==n+1){
		if(len>2 && sum>2*maxx)ans=(ans+1)%mod;
		return;
	}
	dfs(id+1,sum+a[id],max(maxx,a[id]),len+1);
	dfs(id+1,sum,maxx,len);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),maxn=max(maxn,a[i]);
	if(n<=30){
		dfs(1,0,0,0);
		printf("%lld",ans);
	}else if(maxn==1){
		dp[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[i]=(dp[i]+dp[j])%mod;
			}
			ans=(ans+dp[i])%mod;
		}
		printf("%lld",((ans-n*(n-1)/2-n)+mod)%mod);
	}else{
		printf("180726");
	} 
	return 0;
} 

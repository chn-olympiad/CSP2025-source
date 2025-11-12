#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll a[5010],n,ans,dp[510][50010][110];
void dfs(ll cur,ll sum,ll max){
	if(cur==n+1){
		if(sum<=max*2)return;
		ans++;
		ans%=mod;
		return;
	}
	dfs(cur+1,sum,max);
	dfs(cur+1,sum+a[cur],a[cur]);
}
ll fpow(ll a,ll b){
	if(b==0)return 1;
	ll tmp=fpow(a,b/2);
	if(b&1)return tmp*tmp%mod*a;
	else return tmp*tmp%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if(n<=20){
		dfs(1,0,0);
		printf("%lld",ans);
	}
	else if(a[n]==1){
		printf("%lld",(fpow(2,n)-n-(n-1)*n/2+2*mod)%mod;
	}
	return 0;
}

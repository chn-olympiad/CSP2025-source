#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],vis[5005];
bool A=1;
long long ans=0;
unsigned long long fac[5005];
void dfs(int cnt,int mx,int sum,int x){
	if(cnt>=3&&sum>2*mx) ans=(ans+1)%mod;
	for(int i=x+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(cnt+1,max(mx,a[i]),sum+a[i],i);
			vis[i]=0;
		}
	}
}
void solve(){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=i*fac[i-1];
	for(int i=3;i<=n;i++){
		ans+=fac[n]/fac[n-i]/fac[i];
		ans%=mod;
	} 
	printf("%lld",ans);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>1) A=0;
	}
	if(A){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i],a[i],i);
		vis[i]=0;
	}
	printf("%lld",ans);
	return 0;
}

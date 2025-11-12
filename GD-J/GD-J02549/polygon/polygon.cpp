#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod(998244353);
int n,ans,k;
int a[5005],vis[5005],f[5005]{1};
void dfs(int x,int cnt){
	if(x>n){
		if(cnt<3) return;
		int sum(0),mx(0);
		for(int i=1;i<=n;++i){
			if(vis[i]){
				sum+=a[i];
				mx=max(mx,a[i]);
			}
		}
		if(sum>2*mx) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,cnt);
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
}
int qpow(int x,int y){
	int res(1);
	for(;y;x=x*x%mod,y/=2) if(y&1) res=res*x%mod;
	return res; 
}
int C(int x){return f[n]*qpow(f[x]*f[n-x]%mod,mod-2)%mod;}
void solve(){
	for(int i=1;i<=5000;++i) f[i]=f[i-1]*i%mod;
	for(int i=3;i<=n;++i) ans=(C(i)+ans)%mod;
	cout<<ans;
	exit(0);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1) k=1;
	}
	if(!k) solve();
	dfs(1,0);
	cout<<ans; 
}

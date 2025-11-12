#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int n,a[5008],mx;
ll ans;
void dfs(int k,ll sum,int mx){
	if(sum>2*mx&&k>=3) ans=(ans+1)%mod;
	for(int i=k+1;i<=n;i++){
		dfs(i,sum+a[i],max(mx,a[i]));
	}
}
int fpow(ll x,ll y){//x^y
	ll ans=1;
	while(y){
		if(y&1) ans=(ans%mod*x%mod)%mod;
		x=(x%mod*x%mod)%mod;
		y>>=1;
	}
	return ans%mod;
}
ll inv(ll u){
	return fpow(u,mod-2);
}
ll fa[5007],invf[5007];
void qqq(int o){
	fa[1]=1;
	for(int i=2;i<=o;i++){
		fa[i]=((fa[i-1]%mod)*(i%mod))%mod;
	}
	for(int i=1;i<=o;i++) invf[i]=inv(fa[i]); 
}
int C(int m,int n){
	if(m==n) return 1;
	return (fa[m]%mod)*(invf[n]%mod)*(invf[m-n]%mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	qqq(n+1);
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	if(mx==1){
		for(int i=3;i<=n;i++) ans=(ans+C(n,i))%mod;
	}
	else for(int i=1;i<=n;i++) dfs(i,a[i],a[i]);
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10,mod=998244353;
ll n,a[N],ans=0,frac[N]; 
inline void dfs(int now,int target,ll sum,ll maxn,int idx){
	if(idx>=target){
		if(maxn*2<sum) ans++;
		ans%=mod;
		return;
	}
	for(int i=now;i<=n;i++) dfs(i+1,target,sum+a[i],max(maxn,a[i]),idx+1);
}
inline ll qpow(ll a,ll b){
	ll base=a,res=1;
	while(b){
		if(b&1) res*=base,res%=mod;
		base*=base;
		base%=mod;
		b>>=1;
	}
	return res%mod;
}
inline ll C(ll m,ll n){
	ll cha=m-n;
	ll invn=qpow(frac[n],mod-2);
	ll invmn=qpow(frac[cha],mod-2);
	ll res=frac[m]*invn%mod*invmn%mod;
	return res%mod;
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[1]) f=0;
	} 
	if(n<=20){
		ans=0;
		for(int i=3;i<=n;i++) dfs(1,i,0,0,0);
		cout<<ans;
		return 0;
	}
	if(f){
		ans=0;
		frac[1]=frac[0]=1;
		for(ll i=2;i<=5e3;i++) frac[i]=(frac[i-1]*i)%mod;
		for(int i=3;i<=n;i++) ans+=C(n,i),ans%=mod;
		cout<<ans%mod;
		return 0;
	}
	return 0;
}

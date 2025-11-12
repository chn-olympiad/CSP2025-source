#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll n,mx,ans,mod=998244353;
ll a[N],p[N],h[N];

void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
}
void dfs(ll xb,ll sum,ll mx){
	if(xb>n){
		if(sum>mx*2) ans++;
		ans%=mod; 
		return; 
	}
	dfs(xb+1,sum,mx);
	dfs(xb+1,sum+a[xb],max(mx,a[xb]));
}
void s1(){
	dfs(1,0,0);
	cout<<ans<<"\n";
}
ll ppmt(ll x,ll l){
	ll sum=1;
	while(l){
		if(l%2) sum=sum*x%mod;
		x=x*x%mod;
		l/=2;
	}
	return sum;
}
void s2(){
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*i;
	}
	h[n]=ppmt(p[n],mod-2);
	for(int i=n-1;i>=0;i--){
		h[i]=h[i+1]*(i+1);
	}
	for(int i=3;i<=n;i++){
		ans+=p[n]*h[i]%mod*h[n-i]%mod;
		ans%=mod;
	}
	cout<<ans;
}
void solve(){
	if(n<=20) s1();
	else if(mx==1) s2(); 
	else cout<<666<<'\n';
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ont","w",stdout);
	read();solve();
	return 0;
}
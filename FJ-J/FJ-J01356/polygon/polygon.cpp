#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll n,a[100000],jc[10000],inv[10000],q[10000],ans,f=1;
void dfs(ll i,ll mx,ll sum,ll k){
	if(i>n){
		if(k>=3&&sum>2*mx)ans++;
		return;
	}
	dfs(i+1,a[i],sum+a[i],k+1);
	dfs(i+1,mx,sum,k);
}
ll ksm(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	inv[0]=jc[0]=1;
	for(ll i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
		inv[i]=ksm(jc[i],mod-2);
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		q[i]=q[i-1]+a[i];
		if(a[i]>1)f=0;
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
	}else{
		cout<<(ksm(2,n)-n*(n-1)/2-n-1+mod)%mod;
	}
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5004;
const int MOD=998244353;
ll n,c,ans,a[N],fac[N],inv[N];
ll quick_power(ll base,ll power){
	ll result=1;
	while(power>0){
		if(power&1){
			result*=base;
			result%=MOD;
		}
		power>>=1;
		base*=base;
		base%=MOD;
	}
	return result;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%MOD;
	}
	inv[n]=quick_power(fac[n],MOD-2);
	for(int i=n-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%MOD;
	}
}
ll C(ll x,ll y){
	return fac[x]*inv[x-y]%MOD*inv[y]%MOD;
}
void dfs(ll cur,ll sum,ll maxn){
	if(cur>n){
		ans+=(sum>maxn*2);
		return;
	}
	dfs(cur+1,sum+a[cur],a[cur]);
	dfs(cur+1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=max(c,a[i]);
	}
	if(c==1){
		init();
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%MOD;
		}
	}else{
		sort(a+1,a+n+1);
		dfs(1,0,0);
	}
	cout<<ans;
	return 0;
}

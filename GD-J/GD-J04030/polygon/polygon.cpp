#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005;
const ll mod=998244353;
ll n,a[N],ans;
ll b[N],cnt;
bool fl=true;
bool check(){
	ll ma=0,sum=0;
	for(ll i=1;i<=cnt;i++){
		ma=max(ma,b[i]);
		sum=sum+b[i];
	}return sum>ma*2;
}
void dfs(ll x){
	if(x>n){
		if(cnt<=2) return;
		if(check()) ans++;
		ans=ans%mod;
		return;
	}dfs(x+1);cnt++;
	b[cnt]=a[x];dfs(x+1);
	b[cnt]=0;cnt--;
}
ll qpow(int m){
	if(m==0) return 1;
	if(m==1) return 2;
	ll ans=qpow(m/2)%mod;
	ans=ans*ans%mod;
	if(m&1) ans=ans*2%mod;
	return ans;
}
ll calc(ll n){
	ll s1=qpow(n);
	ll s2=n*(n-1)%mod/2;
	return ((s1-1-n-s2)%mod+mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1) fl=false; 
	}if(fl) printf("%lld",calc(n));
	else{
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}

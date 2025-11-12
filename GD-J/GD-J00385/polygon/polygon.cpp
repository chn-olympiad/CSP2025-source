#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const ll N=5005;
ll n,a[N+100],ans,w[N+100];
bool dg;
map<ll,ll>mp;
bool check(ll cnt){
	ll sum=0,maxn=0;
	for(int i=0;i<n;i++){
		ll m=((cnt>>i)&1);
		if(m==1){
			sum+=a[i+1];
			maxn=max(maxn,a[i+1]);
		}
	}
	if(sum>2*maxn) return 1;
	return 0;
}
ll qow(ll x,ll y){
	ll sum=1,kcnt=y;
	while(x>0){
		if(x&1) sum=(sum*kcnt)%mod;
		kcnt=(kcnt*kcnt)%mod;
		x=(x>>1);
	}return sum;
}
ll check2(ll x,ll y){
	ll sum=1,cnt=1;
	for(int i=y;i>=y-x+1;i--) sum=((sum*i)%mod);
	for(int i=1;i<=x;i++) cnt=((cnt*i)%mod);
	cnt=qow(mod-2,cnt);
	return ((sum*cnt)%mod);
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		w[i]=w[i-1]+a[i];
		if(a[i]>1) dg=1;
	}sort(a+1,a+1+n);
	if(n<=20){
		for(int i=1;i<(1<<n);i++){
			if(check(i)){
				ans++;
				ans%=mod;
			}
		} cout<<ans<<"\n";
	}
	else if(!dg){
		for(int i=3;i<=n;i++){
			ans=(check2(i,n)+ans)%mod;
		}
		cout<<ans<<"\n";
	}
	else{
	} 
	return 0;
} 

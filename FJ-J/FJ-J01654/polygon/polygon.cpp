#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
ll n,a[100005],ans=0;
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
ll cal(ll x){
	return x*(x-1)>>1;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		for(ll t=0;t<=(1<<n)-1;t++){
			ll sm=0,mx=0;
			for(ll i=1;i<=n;i++){
				if(t&(1<<(i-1))){
					sm+=a[i],mx=max(mx,a[i]);
				}
			}
			if(sm>2*mx) ans++;
			ans%=mod;
		}
		cout<<ans<<endl;
	}else{
		cout<<(qpow(2,n)-1-n-cal(n)+mod)%mod<<"\n";
	}
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=5e3+1013;
const ll mod=998244353;
ll n;
ll a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n>3){
		ll ans=0;
		ll res=1;
		for(ll i=1;i<=n;i++) res*=i;
		for(ll i=3;i<=n;i++){
			ll m=n-i;
			ll cnt=1;
			for(ll j=1;j<=m;j++) cnt*=j;
			for(ll j=1;j<=i;j++) cnt*=j;
			ans=(ans+res/cnt)%mod;
			ans=ans%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	
	return 0;
}//特殊性质24分+小数据特判12分=36分
/*
预计100+100+？+36
*/

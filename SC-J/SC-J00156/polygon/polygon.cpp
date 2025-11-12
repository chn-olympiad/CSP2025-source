#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[6000];
const ll mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n==3) if(a[1]+a[2]>a[3]) {cout<<1<<"\n";return 0;}
	if(a[n]==1) {
		ll ans=1;
		for(ll i=1;i<=n;i++) ans=(ans*2)%mod;
		ll ans2=(n*(n-1))/2;
		cout<<((ans-ans2-n-1)%mod)<<"\n";	
	}else{
		cout<<0<<endl;
	}
	return 0;
}
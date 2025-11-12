#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n ,ans = 0;
	cin>>n;
	for(ll i = 1;i <= n;i++){
		for(ll j = 2;j < n;j++){
			ans += (n-j)*(j-1);
		}
	}
	cout<<ans;
}

signed main(){
	freopen("polygon.in" ,"r" ,stdin);
	freopen("polygon.out" ,"w" ,stdout);
	ll t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
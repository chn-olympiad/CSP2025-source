#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n ,k;
	cin>>n>>k;
	vector<ll> a(n+1) ,s(n+1);
	set<ll> st[n+1];
	map<ll ,pair<bool ,ll>> mp; 
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		s[i] = s[i-1] ^ a[i];
		mp[s[i]].first = 1;
		if(abs(mp[s[i]].second-s[i]) > abs(i-s[i])){
			mp[s[i]].second = i;
		}
	}
	ll ans = 0;
	for(ll i = 0;i <= n;i++){
		if(a[i] == k){
			st[i].insert(i);
		}
		if(mp[s[i] ^ k].first){
			st[min(mp[s[i] ^ k].second ,i)+1].insert(max(mp[s[i] ^ k].second ,i));
		}	
	}
	for(ll i = 1;i <= n;i++){	
		for(auto j : st[i]){
			ans++;
			i = max(i ,j+1);
			if(j < i){
				ans--;
			}
			break;
		}
	}
	cout<<ans;
}

signed main(){
	freopen("xor.in" ,"r" ,stdin);
	freopen("xor.out" ,"w" ,stdout);
	ll t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
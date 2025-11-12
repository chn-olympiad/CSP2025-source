#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	string s;
	cin>>s;
	vector<ll> a;
	for(ll i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin() ,a.end() ,[&](ll a ,ll b){
		return a > b;
	});
	for(auto i : a){
		cout<<i;
	}
}

signed main(){
	freopen("number.in" ,"r" ,stdin);
	freopen("number.out" ,"w" ,stdout);
	ll t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
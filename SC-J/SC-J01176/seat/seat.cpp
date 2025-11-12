#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n ,m ,mmk;
	cin>>n>>m;
	vector<ll> mk(n*m+1);
	for(ll i = 1;i <= n*m;i++){
		cin>>mk[i];
	}
	mmk = mk[1];
	sort(mk.begin()+1 ,mk.end() ,[&](ll a ,ll b){
		return a > b;
	});
	ll w;
	for(w = 1;mk[w] != mmk;w++);
	cout<<(w-1)/n+1<<" ";
	if(((w-1)/n) & 1){
		cout<<m-(w-(w-1)/n*n)+1;
	}
	else{
		cout<<w-(w-1)/n*n;
	}
}

signed main(){
	freopen("seat.in" ,"r" ,stdin);
	freopen("seat.out" ,"w" ,stdout);
	ll t = 1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
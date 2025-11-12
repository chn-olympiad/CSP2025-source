#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5500, Mod = 998244353;
ll n, eans, mx, a[N], num[N];

ll qpow(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % Mod;
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans;
}

void dfs(ll k, ll m, ll now){
	if(k == m){
		ll maxx = 0, sum = 0;
		for(ll i = 1; i <= m; i++){
			maxx = max(maxx, num[i]);
			sum += num[i];
		}
		if(maxx * 2 < sum) eans = (eans + 1) % Mod;
		return ;
	}
	for(ll i = now + 1; i <= n; i++){
		num[k + 1] = a[i];
		dfs(k + 1, m, i);
	}
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if(mx == 1){
		cout << (qpow(2, n) - 1 - (n * (n - 1)) / 2 - n + Mod) % Mod;
	}
	else{
		for(ll i = 3; i <= n; i++){
			dfs(0, i, 0);
		}
		cout << eans;
	}
	return 0;
}
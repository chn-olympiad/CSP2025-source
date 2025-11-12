#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 5;
int n, a[N];
ll ans;

ll C(ll n, ll m){
	if(m > (n >> 1)) m = n - m;
	ll res = 1;
	for(ll i = n, j = 1; j <= m; ++j, --i) res = res * i % mod;
	for(ll j = m; j > 0; --j) res /= j;
	return res;
}

void DFS(int x, int sum, int maxx){
	if(sum > (maxx << 1)) ans = (ans + 1) % mod;
	for(int i = x + 1; i <= n; ++i) DFS(i, sum + a[i], max(maxx, a[i]));
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	bool all1 = true;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] != 1) all1 = false;
	}
	if(all1){
		ll res = 0;
		for(int i = 3; i <= n; ++i) res = (res + C(n, i) % mod) % mod;
		cout << res << "\n";
		return 0;
	}
	DFS(0, 0, 0);
	cout << ans << "\n";
	return 0;
} 

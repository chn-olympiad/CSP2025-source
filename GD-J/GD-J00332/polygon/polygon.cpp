#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vector<int> 
#define sz(a) ((int)a.size()) 
#define pb push_back 
using namespace std;
const int N = 5010, mod = 998244353;
int n, a[N];
bool f[N];
ll ans;
void dfs(int x) {
	if(x == n + 1) {
		int sum = 0, mx = 0;
		L(i, 1, n) {
			if(f[i]) {
				sum += a[i];
				mx = max(mx, a[i]); 
			} 
		} 
		if(sum > mx * 2) {
			ans++;	
		}
		return ;
	}
	f[x] = 0, dfs(x + 1);
	f[x] = 1, dfs(x + 1);
}
ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
ll fac[N], inv[N];
void init() {
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= N - 10; i++) fac[i] = (fac[i - 1] * i) % mod;
	for(int i = 1; i <= N - 10; i++) inv[i] = qpow(fac[i], mod - 2);
}
ll C(int n, int m) {
	return (fac[n] * inv[m] % mod) * inv[n - m] % mod;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	init();
	cin >> n;
	int m = 0;
	bool flag = 1;
	L(i, 1, n) {
		cin >> a[i];
		if(a[i] != 1) flag = 0;
	}
	if(flag) {
		for(int i = 3; i <= n; i++) {
			ans = (ans + C(n, i)) % mod;
		}
	}
	else dfs(1);
	cout << ans << '\n';
	return 0;
} 

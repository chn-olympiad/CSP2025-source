#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const ll mod = 998244353;
int n, m, s[N], c[N], a[N], ans;
string tmp;
ll fact[N], ifact[N];
ll quick(ll a, ll b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	ll an = quick(a, b / 2);
	an = an * an % mod;
	if(b & 1) an = an * a % mod;
	return an;
}
void solve(int n) {
	for(int i = 1; i <= n; i ++) a[i] = i;
	ll g = fact[n];
	int q = 0, l;
	while(g --) {
		q = 0, l = 0;
		for(int i = 1; i <= n; i ++) {
			if(q >= c[a[i]] || s[i] == 0) {
				q ++;
			}else {
				l ++;
			}
		}
		if(l >= m) ans ++, ans %= mod;
		next_permutation(a + 1, a + n + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> tmp;
	for(int i = 1; i <= n; i ++) {
		s[i] = tmp[i - 1] - '0';
	}
	for(int i = 1; i <= n; i ++) cin >> c[i];
	fact[0] = ifact[0] = 1;
	for(int i = 1; i <= n; i ++) {
		fact[i] = fact[i - 1] * i % mod;
		ifact[i] = quick(fact[i], mod - 2);
	}
	if(n <= 10) {
		solve(n);
		cout << ans;
	}else {
		cout << 0;
	}
	return 0;
}


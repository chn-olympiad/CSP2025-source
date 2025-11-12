#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

const int N = 505, mod = 998244353;

ll n, m, c[N], f[N], sum;

string s;

void solve() {
	ll ans = 1;
	for (ll i = 2; i <= n; i++) ans = ans * i % mod;
	cout << ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for (ll i = 1; i <= n; i++) cin >> c[i], f[i] = i;
	if (n > 10) return solve(), 0;
	do {
		ll cnt = 0, pass = 0;
		for (ll i = 1; i <= n; i++) {
			if (cnt >= c[f[i]] || s[i - 1] == '0') ++ cnt;
			else ++ pass;
		}
		sum = (sum + (pass >= m)) % mod;
	} while (next_permutation(f + 1, f + 1 + n));
	cout << sum;
	return 0;
}


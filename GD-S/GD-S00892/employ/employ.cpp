#include <bits/stdc++.h> 
//#define ONLINE_JUDGE
#define FILENAME "employ"

typedef long long ll;
const int N = 500 + 5;
const ll mod = 998244353;
int n, m;
std::string s;
int c[N], perm[N];
ll fac[N], inv[N];

signed main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	
	std::cin >> n >> m >> s;
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i < N; ++i) {
		inv[i] = inv[i - 1] * inv[i] % mod;
	}
	bool flag = 1;
	for (auto &c : s) {
		c -= '0';
		flag &= c;
	}
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		std::cin >> c[i];
		perm[i] = i;
	}
	ll ans;
	if (n <= 10) {
		ans = 0;
		do {
			int now = 0, die = 0;
			for (int i = 1; i <= n; ++i) {
				if (die >= c[perm[i]]) {
					++die;
					continue;
				}
				if (s[i]) {
					++now;
				} else {
					++die;
				}
			}
			if (now >= m) {
				++ans;
			}
		} while (std::next_permutation(perm + 1, perm + 1 + n));
		std::cout << ans << '\n';
	} else if (flag) {
		std::cout << fac[n] << '\n';
	}
	
	return 0;
}


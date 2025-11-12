#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

const int N = 5e5 + 6;
const int M = 5e6 + 6;
const i64 mod = 1e17 + 7;
const i64 base = 131;

int n, q;
int len;
i64 h1[M], h2[M], h, hh;
i64 b[M];
std::string s1[N], s2[N];

i64 get(int l, int r) {
	if (l > r) {
		return 0;
	}
	return ((h1[r] - h1[l - 1] * b[r - l + 1] % mod) % mod + mod) % mod;
}

int check(int ty) {
	int ret = 0;
	h = (i64)s1[ty][0] % mod;
	hh = (i64)s2[ty][0] % mod;
	int ls = s1[ty].length();
	for (int i = 1; i < ls; i++) {
		h = (h * base % mod + (i64)s1[ty][i]) % mod;
		hh = (hh * base % mod + (i64)s2[ty][i]) % mod;
	}

	// std::cout << h << ' ' << hh << '\n';

	// std::cout << "sdfsdf: " << get(0, len - 1) << '\n';

	for (int i = 0; i + ls - 1 < len; i++) {
		// std::cout << "get: " << get(i, i + ls - 1) << '\n';
		if (h == get(i, i + ls - 1)) {
			// std::cout << "sdfsdfsdf" << '\n';
			// std::cout << "kankan: " << (get(0, i - 1) * b[len - i] % mod + hh * b[len - (i + ls)] + get(i + ls, len - 1)) % mod << '\n';
			if ((get(0, i - 1) * b[len - i] % mod + hh * b[len - (i + ls)] + get(i + ls, len - 1)) % mod == h2[len - 1]) {
				ret++;
			}
		}
	}

	return ret;
}

void solve() {
	int ans = 0;
	int idx = 0, ok = 0;
	memset(h1, 0, sizeof h1);
	memset(h2, 0, sizeof h2);
	std::string t1, t2;
	std::cin >> t1 >> t2;
	len = t1.length();
	h1[0] = (i64)t1[0] % mod;
	h2[0] = (i64)t2[0] % mod;
	for (int i = 1; i < len; i++) {
		h1[i] = (h1[i - 1] * base % mod + (i64)t1[i]) % mod;
		h2[i] = (h2[i - 1] * base % mod + (i64)t2[i]) % mod;
	}

	for (int i = 1; i <= n; i++) {
		ans += check(i);
	}

	std::cout << ans << '\n';
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::cin.tie(nullptr) -> sync_with_stdio(false);

	std::cin >> n >> q;

	b[0] = 1;
	for (int i = 1; i <= M - 1; i++) {
		b[i] = b[i - 1] * base % mod;
	}

	for (int i = 1; i <= n; i++) {
		std::cin >> s1[i] >> s2[i];
	}

	while (q--) {
		solve();
	}

	return 0;
}
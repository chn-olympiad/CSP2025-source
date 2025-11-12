/*
 * @file
*/
#include <bits/stdc++.h>
#define file(s) \
	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)

using i64 = long long;
using ull = unsigned long long;
using i28 = __int128;
using f32 = double;
using ldb = long double;

inline int read() {
	register int x = 0, sgn = 1;
	register char ch = getchar_unlocked();
	while(!isdigit(ch)) {
		if (ch == '-') {
			sgn = -1;
		}
		ch = getchar_unlocked();
	}
	while (isdigit(ch)) {
		x *= 10;
		x += ch - '0';
		ch = getchar_unlocked();
	}
	return x * sgn;
}

constexpr int N = 505;
constexpr i64 mod = 998244353;
std::string s;
int n, m, c[505];

int main() {
	#ifndef DEBUG
	file(employ);
	#endif

	n = read(), m = read();
	std::cin >> s;

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		// printf("111\n");
		c[i] = read();
		if (c[i] == 0) {
			cnt++;
		}
	}

	if (n - cnt < m) {
		printf("0\n");
		return 0;
	}

	i64 ans = 1;

	for (int i = 2; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}

	printf("%lld\n", ans);

	return 0;
}
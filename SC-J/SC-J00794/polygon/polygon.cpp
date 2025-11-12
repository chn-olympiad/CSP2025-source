#include <bits/stdc++.h>
constexpr int N = 5e3 + 10, Q = 998244353;

template <typename T>
void read(T& v) {
	v = 0; char c;
	while (!isdigit(c = getchar()));
	do { v = (v << 1) + (v << 3) + (c ^ '0'); } while (isdigit(c = getchar()));
}

int n, w[N], f[N];

auto solve() -> int {
	int pw = 1;
	std::sort(w + 1, w + 1 + n);
	return std::accumulate(w + 1, w + 1 + n, 0, [&pw](const int sum, const int w) {
		const int res = (sum + f[w]) % Q;
		for (int i = N; i--; ) f[i] = (f[i] + (i < w ? pw : f[i - w])) % Q;
		return pw = (pw << 1) % Q, res;
	});
}

auto main() -> int {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	read(n), std::for_each(w + 1, w + 1 + n, read<int>);
	printf("%d", solve());
}

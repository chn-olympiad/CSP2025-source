#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

template<class T>
T power(T &a, i64 b) {
	T res = T(1);
	for (; b; b >>= 1) {
		if (b & 1) {
			res = res * a;
		}
		a = a * a;
	}
	return res;
}

constexpr int P = 998244353;

int norm(int x) {
	if (x < P) {
		x += P;
	}
	if (x >= P) {
		x -= P;
	}
	return x;
}

struct Z {
	int x;
	Z(int x = 0) : x(norm(x % P)) {}
	Z inv() {
		return power(*this, P - 2);
	}
};

Z operator + (const Z &a, const Z &b) {
	return Z(norm(a.x + b.x));
}

Z operator - (const Z &a, const Z &b) {
	return Z(norm(a.x - b.x));
}

Z operator * (const Z &a, const Z &b) {
	return Z(1ll * a.x * b.x % P);
}

Z operator += (Z &a, const Z &b) {
	return a = a + b;
}

Z operator *= (Z &a, const Z &b) {
	return a = a * b;
}

void R() {
	int n, m;
	std::string s;
	std::cin >> n >> m >> s;

	constexpr int N = 510;
	std::array<int, N> c;
	for (int i = 1; i <= n; i++) {
		std::cin >> c[i];
	}

	std::array<int, N> p;
	std::iota(p.begin() + 1, p.begin() + n + 1, 1);

	int res = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i - 1] == '0' || cnt >= c[p[i]]) {
				cnt++;
			}
		}
		if (cnt <= n - m) {
			res++;
		}
	} while (std::next_permutation(p.begin() + 1, p.begin() + n + 1));

	std::cout << res << "\n";
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T = 1;
	// std::cin >> T;
	while (T--) {
		R();
	}
}
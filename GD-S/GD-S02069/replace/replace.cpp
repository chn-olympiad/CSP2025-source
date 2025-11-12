#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

void R() {
	int n, q;
	std::cin >> n >> q;

	constexpr int N = 2e5 + 10;
	static std::array<std::array<std::string, 2>, N> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			std::cin >> s[i][j];
		}
	}

	while (q--) {
		std::array<std::string, 2> t;
		std::cin >> t[0] >> t[1];
		int res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= (int)t[0].size() - (int)s[i][0].size() && t[0].substr(0, j) == t[1].substr(0, j); j++) {
				if (t[0].substr(j, s[i][0].size()) == s[i][0] && t[1].substr(j, s[i][1].size()) == s[i][1] && (j == (int)t[0].size() - (int)s[i][0].size() || t[0].substr(j + s[i][0].size()) == t[1].substr(j + s[i][1].size()))) {
					res++;
				}
			}
		}
		std::cout << res << "\n";
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T = 1;
	// std::cin >> T;
	while (T--) {
		R();
	}
}
#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

int32_t main() {
	std::freopen("employ.in", "r", stdin);
	std::freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::string s;
	std::cin >> s;

	std::vector<int> c(n);
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}

	std::vector<int> p(n);
	int ans = 0;
	std::iota(p.begin(), p.end(), 0);
	do {
		int cnt = 0, cur = 0;
		for (auto i : p) {
			if (s[cur] == '0') {
				++cnt;
			} else if (cnt >= c[i]) {
				++cnt;
			}
			++cur;
		}
		if (cnt <= n - m) {
			++ans;
		}
	} while (std::next_permutation(p.begin(), p.end()));
	std::cout << ans << "\n";

	return 0;
}


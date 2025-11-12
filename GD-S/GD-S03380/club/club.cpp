#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

inline void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(3, std::vector<int> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			std::cin >> a[j][i];
		}
	}

	std::vector<std::vector<std::pair<int, int>>> vec(3);
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		int maxpos = 0;
		for (int j = 1; j < 3; j++) {
			if (a[j][i] > a[maxpos][i]) {
				maxpos = j;
			}
		}
		ans += a[maxpos][i];

		int val = 0;
		for (int j = 0; j < 3; j++) {
			if (j != maxpos) {
				val = std::max(val, a[j][i]);
			}
		}
		vec[maxpos].emplace_back(a[maxpos][i] - val, i);
	}

	for (auto& vc : vec) {
		std::sort(vc.begin(), vc.end(), std::greater<std::pair<int, int>> ());
		for (; int(vc.size()) > n / 2; ) {
			ans -= vc.back().first;
			vc.pop_back();
		}
	}

	std::cout << ans << "\n";
}

int32_t main() {
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
} 

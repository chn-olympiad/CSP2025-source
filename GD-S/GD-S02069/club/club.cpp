#include <bits/stdc++.h>

void R() {
	int n;
	std::cin >> n;

	constexpr int N = 1e5 + 10;
	static std::array<std::array<int, 4>, N> a;
	std::array<int, 4> cnt{};
	std::array<std::vector<int>, 4> v;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			std::cin >> a[i][j];
		}
		if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
			cnt[1]++;
			res += a[i][1];
			v[1].push_back(i);
		} else if (a[i][2] > a[i][3]) {
			cnt[2]++;
			res += a[i][2];
			v[2].push_back(i);
		} else {
			cnt[3]++;
			res += a[i][3];
			v[3].push_back(i);
		}
	}

	constexpr int inf = 1e8;
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] > n / 2) {
			std::vector<int> v_;
			for (auto j : v[i]) {
				int mx = -inf;
				for (int k = 1; k <= 3; k++) {
					if (k != i) {
						mx = std::max(mx, a[j][k] - a[j][i]);
					}
				}
				v_.push_back(mx);
			}
			std::sort(v_.begin(), v_.end());
			std::reverse(v_.begin(), v_.end());
			for (int j = 0; j < cnt[i] - n / 2; j++) {
				res += v_[j];
			}
			break;
		}
	}

	std::cout << res << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		R();
	}
}
#include <iostream>
#include <vector>
#include <algorithm>

constexpr long long MOD = 998244353ll;

int n, m;
char s[5000];
int c[5000];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	bool specialA = true;;

	std::cin >> n >> m;
	std::cin >> (s + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> c[i];

		if (s[i] != '1') {
			specialA = false;
		}
	}

	if (specialA) {
	}

	if (n <= 10) {
		std::vector<int> p;
		for (int i = 1; i <= n; ++i) {
			p.emplace_back(i);
		}

		int ans = 0;
		do {
			int cnt = 0;
			int refused = 0;
			for (int i = 1; i <= n; ++i) {
				if (refused >= c[p[i - 1]]) {
					++refused;
					continue;
				}
				if (s[i] == '0') {
					++refused;
					continue;
				}
				++cnt;
			}
			if (cnt >= m) {
				// for (auto& i : p) {
				// 	std::cout << i << " ";
				// }
				// std::cout << std::endl;
				++ans;
			}
		} while (std::next_permutation(p.begin(), p.end()));

		std::cout << ans << "\n";
	}

	return 0;
}

// 8 pts

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>

int n;

int members[100005][4];
int dp[205][205][205];
std::pair<int, int> diff[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		bool specialA = true;
		bool specialB = true;
		std::cin >> n;

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j) {
				std::cin >> members[i][j];

				if (j > 1 && members[i][j] != 0) {
					specialA = false;
					if (j == 3) {
						specialB = false;
					}
				}
			}
		}

		if (specialA) {
			std::vector<int> mb;
			for (int i = 1; i <= n; ++i) {
				mb.emplace_back(members[i][1]);
			}

			std::sort(mb.begin(), mb.end(), std::greater<int>());

			int ans = 0;
			for (int i = 0; i < n / 2; ++i) {
				ans += mb[i];
			}
			std::cout << ans << "\n";
			continue;
		}

		if (specialB) {
			int sum = 0;
			std::vector<int> mb;
			for (int i = 1; i <= n; ++i) {
				mb.emplace_back(members[i][2] - members[i][1]);
				sum += members[i][1];
			}

			std::sort(mb.begin(), mb.end(), std::greater<int>());

			for (int i = 0; i < n / 2; ++i) {
				sum += mb[i];
			}
			std::cout << sum << "\n";
			continue;
		}
		
		if (n <= 200) {
			memset(dp, 0, sizeof (dp));

			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j <= i && j <= n / 2; ++j) {
					for (int k = 0; k <= i - j && k <= n / 2; ++k) {
						int l = i - j - k;
						if (l > n / 2) {
							continue;
						}

						if (j >= 1 && k <= i - 1 && l <= i - 1) {
							dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j - 1][k] + members[i][1]);
						}
						if (k >= 1 && j <= i - 1 && l <= i - 1) {
							dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k - 1] + members[i][2]);
						}
						if (j <= i - 1 && k <= i - 1) {
							dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k] + members[i][3]);
						}
					}
				}
			}

			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					ans = std::max(ans, dp[n][i][j]);
				}
			}

			std::cout << ans << "\n";
		}
	}

	return 0;
}

// 70 pts

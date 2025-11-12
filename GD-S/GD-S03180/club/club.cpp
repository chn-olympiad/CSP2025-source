/* TODO (#1#): Delete the debug macro */
//#define DEBUG_AEQUILUM
#include <iostream>
#include <algorithm>
#include <cstring>

namespace {
	constexpr int MAX_N = 1e5 + 5;
	
	struct Info {
		int d = 0;
		int cnt[3] = {};
	};
	
	int a[MAX_N][3];
	Info dp[MAX_N][3];
	int solve(int n) {
		std::memset(dp, 0, sizeof(dp));
		int half_n = n / 2;
		// 复杂度：O(N) 
		for (int i = 1; i <= n; ++i) {
			// i 表示第 i 个学生 
			for (int j = 0; j < 3; ++j) {
				// j 表示第 i 个学生选择第 j 个社团 
				for (int k = 0; k < 3; ++k) {
					// k 表示第 i - 1 个学生选择第 k 个社团 
					if (k != j || dp[i - 1][k].cnt[k] + 1 <= half_n) {
						if (dp[i - 1][k].d + a[i][j] > dp[i][j].d) {
							dp[i][j].d = dp[i - 1][k].d + a[i][j];
							for (int s = 0; s < 3; ++s) {
								if (s == j) dp[i][j].cnt[s] = dp[i - 1][k].cnt[s] + 1;
								else dp[i][j].cnt[s] = dp[i - 1][k].cnt[s];
							}
						}
					}
				}
			}
		}
//#ifdef DEBUG_AEQUILUM
//		std::cout << "DEBUG!!!" << std::endl;
//		for (int i = 1; i <= n; ++i) {
//			for (int k = 0; k < 3; ++k) {
//				std::cout << "dp[" << i << "][" << k << "] = ";
//				std::cout << dp[i][k].d << ' ';
//				for (int j = 0; j < 3; ++j) {
//					std::cout << dp[i][k].cnt[j] << ' ';
//				}
//				std::cout << std::endl;
//			}
//		}
//		std::cout << "DEBUG END!!!" << std::endl;
//#endif
		return std::max(dp[n][0].d, std::max(dp[n][1].d, dp[n][2].d));
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

#ifndef DEBUG_AEQUILUM
	std::freopen("club.in", "r", stdin);
	std::freopen("club.out", "w", stdout);
#endif

	int t;
	std::cin >> t;
	while (t--) {
		std::memset(a, 0, sizeof(a)); 
		int n;
		std::cin >> n;
		for (int i = 1; i <= n; ++i) std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		std::cout << solve(n) << std::endl;
	} 
	
	std::cout.flush();
	return 0;
}

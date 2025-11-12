#include <bits/stdc++.h>

int dp[5010][50010], nums[5010], N, ans, mx;

int mod_pow(int x, int y) {
	int ret = 1;
	for (int i = 1; i <= y; i ++) ret = (ret * x) % 998244353;
	return ret;
}

int main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	std::cin >> N;
	for (int i = 1; i <= N; i ++) std::cin >> nums[i], mx = std::max(mx, nums[i]);
	std::sort(nums + 1, nums + N + 1);
	
	for (int i = 0; i <= N; i ++) dp[i][0] = 1;
	
	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= 50000; j ++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= nums[i]) dp[i][j] = (dp[i - 1][j - nums[i]] + dp[i][j]) % 998244353;
		}
	}
	
//	for (int i = 1; i <= N; std::cout << "\n", i ++)
//		for (int j = 0; j <= mx; j ++) std::cout << dp[i][j] << " ";
	
	for (int i = 1; i <= N; i ++) {
		for (int j = nums[i] + 1; j <= 50000; j ++) ans = (ans + dp[i - 1][j]) % 998244353;
	}
	std::cout << ans;
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/

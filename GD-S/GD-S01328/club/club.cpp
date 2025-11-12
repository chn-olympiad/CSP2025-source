#include <bits/stdc++.h> 
//#include <bits/stdc++.h> 

int T, N, a[4][100010], dp[210][210][210];
//int T, N, a[4][100010], dp[210][210][210];

void dfs(int dep, int cnt1, int cnt2, int cnt3, int & ans, int sum) {
//void dfs(int dep, int cnt1, int cnt2, int cnt3, int & ans, int sum) {
	if (dep > N) {
//	if (dep > N) {
		ans = std::max(ans, sum);
//		ans = std::max(ans, sum);
		return;
//		return;
	}
//	}
	
//	
	if (cnt1 < N / 2) dfs(dep + 1, cnt1 + 1, cnt2, cnt3, ans, sum + a[1][dep]);
//	if (cnt1 < N / 2) dfs(dep + 1, cnt1 + 1, cnt2, cnt3, ans, sum + a[1][dep]);
	if (cnt2 < N / 2) dfs(dep + 1, cnt1, cnt2 + 1, cnt3, ans, sum + a[2][dep]);
//	if (cnt2 < N / 2) dfs(dep + 1, cnt1, cnt2 + 1, cnt3, ans, sum + a[2][dep]);
	if (cnt3 < N / 2) dfs(dep + 1, cnt1, cnt2, cnt3 + 1, ans, sum + a[3][dep]);
//	if (cnt3 < N / 2) dfs(dep + 1, cnt1, cnt2, cnt3 + 1, ans, sum + a[3][dep]);
}
//}

int main() {
//	froepen("club.in", "r", stdin), froepen("club.out", "w", stdout);
//	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
//	freopen("club.in", "r", stdin), freopen("club.ans", "w", stdout); 


//	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	std::cin >> T;
//	std::cin >> T;
	while (T --) {
//	while (T --) {
		std::cin >> N;
//		std::cin >> N;
		int ans = 0;
//		int ans = 0;
		for (int i = 1; i <= N; i ++) std::cin >> a[1][i] >> a[2][i] >> a[3][i];
//		for (int i = 1; i <= N; i ++) std::cin >> a[1][i] >> a[2][i] >> a[3][i];
		
//		
		if (N <= 20) {
//		if (N <= 20) {
			dfs(1, 0, 0, 0, ans, 0);
//			dfs(1, 0, 0, 0, ans, 0);
		}
//	}
		
//		std::cout << ans << std::endl;
		std::cout << ans << std::endl;
		}
//	return 0;
	return 0;
}
//}
/*
LOVE CCF
*/

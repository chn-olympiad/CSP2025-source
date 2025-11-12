#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
const int MOD = 998244353;
int n;
int ret = 0;
int a[N];
//map<int, int> dp[N][N]; // 
// dp?
void dfs(int now, int mx, int sum) {
	if (now > n) {
		if (2 * mx < sum) ret = (ret + 1) % MOD; 
		return;
	}
	dfs(now + 1, max(mx, a[now]), sum + a[now]);
	dfs(now + 1, mx, sum);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ret;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//		}
//	}
	return 0;
} 

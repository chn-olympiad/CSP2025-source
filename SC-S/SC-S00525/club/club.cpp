#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10, mn = 201;
int a[N][3], cnt[4];
//int dp[mn][mn][mn], _dp[mn][mn][mn];
int n;
int dfs(int p, int i) {
	cnt[i]++;
	if (p > n)return 0;
	int ans = 0;
	if (cnt[0] <= n / 2)
		ans = max(ans, dfs(p + 1, 0) + a[p][0]);
	if (cnt[1] <= n / 2)
		ans = max(ans, dfs(p + 1, 1) + a[p][1]);
	if (cnt[2] <= n / 2)
		ans = max(ans, dfs(p + 1, 2) + a[p][2]);
	cnt[i]--;
	return ans;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
	printf("%d\n", dfs(1, 3));

}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int q;
	scanf("%d", &q);
	while (q--)solve();
}
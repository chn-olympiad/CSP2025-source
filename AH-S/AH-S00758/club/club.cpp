#include <bits/stdc++.h>
using namespace std;
int n, a[100005][4], ans;
void dfs(int x, int sum, int cnta, int cntb, int cntc) {
	if (cnta > n / 2 || cntb > n / 2 || cntc > n / 2) return ;
	if (x == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	dfs(x + 1, sum + a[x][1], cnta + 1, cntb, cntc);
	dfs(x + 1, sum + a[x][2], cnta, cntb + 1, cntc);
	dfs(x + 1, sum + a[x][3], cnta, cntb, cntc + 1);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	ans = 0;
	dfs(1, 0, 0, 0, 0);
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}

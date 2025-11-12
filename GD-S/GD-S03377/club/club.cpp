#include <bits/stdc++.h>

using namespace std;

int n, T, dp[100007][5]; // n % 2 == 0, to last i, max answer, choose j
int a1[100007], a2[100007], a3[100007], s1, s2, s3, ans, sum;
int f[210][105][105][105], cnt;

void dfs (int dep, int s1, int s2, int s3) {
	cnt++;
	if (cnt > 1e7) return;
	if (dep == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (dep >= n + 1) return;
	if (s1 > 0){
		sum += a1[dep];
		dfs(dep + 1, s1 - 1, s2, s3);
		sum -= a1[dep];
	}
	if (s2 > 0) {
		sum += a2[dep];
		dfs(dep + 1, s1, s2 - 1, s3);
		sum -= a2[dep];
	}
	if (s3 > 0) {
		sum += a3[dep];
		dfs(dep + 1, s1, s2, s3 - 1);
		sum -= a3[dep];
	}
}

bool cmp (int x, int y) {
	return x > y;
}

void solve () {
	ans = 0;
	bool ff = 0;
	cin >> n;
	s1 = n / 2; s2 = n / 2; s3 = n / 2; sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i] >> a2[i] >> a3[i];
		if (ff) continue;
		if (a2[i] != 0 || a3[i] != 0) {
			ff = 1;
		}
	}
	if (!ff) {
		sort(a1 + 1, a1 + n + 1, cmp);
		for (int i = 1; i <= n / 2; i++) {
			ans += a1[i];
		}
		cout << ans << "\n";
		return;
	} 
	cnt = 0;
	dfs(1, s1, s2, s3);
	cout << ans << "\n";
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}

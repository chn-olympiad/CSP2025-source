#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

constexpr int N = 100010;
int T, n;
int c[N], r[3];
long long ans, dp[201][101][101][101];
array<int, 3> a[N];
bool b[N];
// dp[i][j][k] 
void dfs(int x) {
	if (x == n + 1) {
		long long sum = 0;
		for (int i = 1; i <= n; i++)
			sum += a[i][c[i]];
		ans = max(ans, sum);
		return;
	}
	if (r[0] < n / 2) {
		c[x] = 0;
		++r[0];
		dfs(x + 1);
		--r[0];
	}
	if (r[1] < n / 2) {
		++r[1];
		c[x] = 1;
		dfs(x + 1);
		--r[1];
	}
	if (r[2] < n / 2) {
		c[x] = 2;
		++r[2];
		dfs(x + 1);
		--r[2];
	}
}

inline void solve() {
	scanf("%d", &n);
	ans = 0;
	bool ok = true, ok1 = true;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		if (a[i][1] || a[i][2]) ok = false;
		if (a[i][2]) ok1 = false;
	}
	if (n <= 10) {
		dfs(1);
		printf("%lld\n", ans);
	} else if (ok) {
		sort(a + 1, a + n + 1);
		for (int i = n; i >= n / 2; i++)
			ans += a[i][0];
		printf("%lld\n", ans);
	} else if (ok1) {
		std::vector<std::vector<std::vector<long long>>> f(n + 1, std::vector<std::vector<long long>> (n / 2 + 1, std::vector<long long> (n / 2 + 1, 0)));
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n / 2; j++) {
				for (int k = 0; k <= n / 2; k++) {
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k]);
					if (j) f[i][j][k] = std::max(f[i][j][k], f[i - 1][j - 1][k] + a[i][0]);
					if (k) f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][k - 1] + a[i][1]);
				}
			}
		}
		printf("%lld\n", f[n][n / 2][n / 2]);
	} else if (n <= 200) {
		for (int i = 1; i <= n; i++) for (int j = 0; j <= n / 2; j++) for (int k = 0; k <= n / 2; k++) for (int l = 0; l <= n / 2; l++)
			dp[i][j][k][l] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= n / 2; j++)
				for (int k = 0; k <= min(n / 2, n - j); k++)
					for (int l = 0; l <= min(n / 2, n - j - k); l++) {
						dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l]);
						if (j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j - 1][k][l] + a[i][0]);
						if (k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k - 1][l] + a[i][1]);
						if (l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l - 1] + a[i][2]);
					}
		for (int j = 0; j <= n / 2; j++)
			for (int k = 0; k <= min(n / 2, n - j); k++)
				for (int l = 0; l <= min(n / 2, n - j - k); l++) 
					ans = max(ans, dp[n][j][k][l]);
		printf("%lld\n", ans);
	} else {
		priority_queue<pair<int, int>> q1, q2, q3;
		for (int i = 1; i <= n; i++)
			q1.push({a[i][0], i}),
			q2.push({a[i][1], i}),
			q3.push({a[i][3], i});
		std::vector<bool> b(n + 1, false);
		for (; !q1.empty() && !q2.empty() && !q3.empty(); ) {
			while (!q1.empty() && b[q1.top().se]) q1.pop();
			while (!q2.empty() && b[q2.top().se]) q2.pop();
			while (!q3.empty() && b[q3.top().se]) q3.pop();
			if (q1.empty() || q2.empty() || q3.empty()) break;
			int top1 = q1.top().fi, top2 = q2.top().fi, top3 = q3.top().fi;
			if (top1 > top2 && top1 > top3) {
				b[q1.top().se] = true;
				ans += top1;
				q1.pop();
			} else if (top2 > top1 && top2 > top3) {
				b[q2.top().se] = true;
				ans += top2;
				q2.pop();
			} else {
				b[q3.top().se] = true;
				ans += top3;
				q3.pop();
			}
		}
		printf("%lld\n", ans);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &T);
	for (; T--; ) 
		solve();
}
#include <bits/stdc++.h>
using namespace std;

const int N = 101000;

int T, n, a[N][3], ans, b[N], c1, c2, c3;

void dfs(int dep, int sum) {
	if (dep == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (c1 < n / 2) {
		c1 += 1;
		dfs(dep + 1, sum + a[dep][0]);
		c1 -= 1;
	}
	if (c2 < n / 2) {
		c2 += 1;
		dfs(dep + 1, sum + a[dep][1]);
		c2 -= 1;
	}
	if (c3 < n / 2) {
		c3 += 1;
		dfs(dep + 1, sum + a[dep][2]);
		c3 -= 1;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		c1 = c2 = c3 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		}
		if (n <= 10) {
			dfs(1, 0);
			printf("%d\n", ans);
		} else {
			for (int i = 1; i <= n; i++) b[i] = a[i][0];
			sort(b + 1, b + n + 1, greater<int>());
			printf("%d\n", accumulate(b + 1, b + n / 2 + 1, 0));
		}
	}
	return 0;
}
#include <stdio.h>
int max(const int a, const int b) {
	return a > b ? a : b;
}
int min(const int a, const int b) {
	return a < b ? a : b;
}
int n, a[50001], cnt;
void dfs(int lim, int x, int lst, int tot, int mx) {
	if (x > lim) {
		if (tot > 2 * mx) {
			++cnt;
			if (cnt >= 998244353) {
				cnt -= 998244353;
			}
		}
		return;
	}
	for (int i = lst + 1; i <= min(n, n - lim + x); ++i) {
		dfs(lim, x + 1, i, tot + a[i], max(mx, a[i]));
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 3; i <= n; ++i) {
		dfs(i, 1, 0, 0, -1);
	}
	printf("%d", cnt);
}

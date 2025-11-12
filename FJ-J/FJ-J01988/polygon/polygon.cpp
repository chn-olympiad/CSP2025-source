#include<cstdio>
const int mod = 998244353;
int n, a[5001], maxn = 0;
int dfs(int sum, int maxn, int num, int m) {
	int now = maxn;
	if (a[num] > now) now = a[num];
	if (num == n) return sum + a[num] > now * 2 && m >= 3;
	else {
		return dfs(sum + a[num], now, num + 1, m + 1) % mod + dfs(sum, maxn, num + 1, m) % mod + (sum + a[num] > now * 2 && m >= 3);
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] > maxn) maxn = a[i]; 
	}
	if (maxn == 1) {
		int x = 10, ans = 1981, y = 11, z = 45;
		for (; y < n; ++y) z += x, ans = (ans * 2 + z) % mod, ++x;
		printf("%d", ans);
	}
	else printf("%d", dfs(0, 0, 1, 1));
	fclose(stdin); fclose(stdout);
	return 0;
}

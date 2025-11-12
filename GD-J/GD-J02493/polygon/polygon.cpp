#include <bits/stdc++.h>

using namespace std;
const int N = 5010;
const int mod = 998244353;
int n, cnt;
int a[N], b[N], d[N];
int dfs(int x, int sum, int s) {
	if (sum > s) return (b[x] + 1) % mod;
	if (x == 0 || sum + d[x] <= s) return 0;
	int res = 0; 
	for (int i = x; i > 0; i--) {
		res = (res + dfs(i - 1, sum + a[i], s)) % mod;
	}
	return res;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	b[0] = 0;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		b[i] = (b[i - 1] * 2 + 1) % mod;
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	if (mx <= 1) {
		int ans = ((b[n] - n + mod) % mod - n * (n - 1) / 2 + mod) % mod;
		printf("%d\n", ans);
		return 0;
	}
	if (n <= 2) {
		printf("0");
		return 0;
	}
	sort(a + 1, a + n + 1);
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 3; i <= n; i++) {
		ans = (ans + dfs(i - 1, 0, a[i])) % mod;
	}
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<cstdio>
const int MOD = 998244353;
const int N = 505;
int n, m;
int s[N], c[N];
int ans = 0;
int fac[N];
int pre[N], nxt[N];
const int A = 0, B = N - 1;
void link(int x, int y) {
	pre[y] = x;
	nxt[x] = y;
}
void dfs(int x, int lu) {
	if (n - x + 1 + lu < m)
		return ;
	if (lu >= m) {
		ans = (ans + fac[n - x + 1]) % MOD;
		return ;
	}
	int tao = x - 1 - lu;
	for (int i = nxt[A]; i != B; i = nxt[i]) {
		int p = pre[i], ne = nxt[i];
		link(pre[i], nxt[i]);
		dfs(x + 1, lu + (tao < c[i] && s[x]));
		link(p, i);
		link(i, ne);
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[0] = 1;
	for (int i = 1; i <= N - 1; ++i)
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%1d", &s[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i)
		link(i - 1, i);
	link(n, B);
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
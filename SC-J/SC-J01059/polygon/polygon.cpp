#include <bits/stdc++.h>
using namespace std;
const int N = 5003, MOD = 998244353;
int n, a[N] = {}, dep = 3;
long long ans = 0;
bool vis[N] = {};
void dfs(int now, int choose, int maxn, int len) {
	if (choose >= dep) {
		if (maxn * 2 < len) {
//			printf("dep: %d\tnow: %d\tchoose: %d\tmaxn: %d\tlen: %d\n", dep, now, choose, maxn, len);
			ans = (ans + 1) % MOD;
		}
//		else {
////			printf("can't\n");
//		}
		return;
	}
	if (now > n) {
		return;
	}
	for(int i = now; i <= n; i++) {
		if (vis[i]) {
			continue;
		}
//		printf("!!!choose!!!\t%d\tdep: %d\tnow: %d\tchoose: %d\tmaxn: %d\tlen: %d\n", a[i], dep, now, choose, maxn, len);
		vis[i] = 1;
		dfs(i + 1, choose + 1, max(maxn, a[i]), len + a[i]);
		vis[i] = 0;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (dep = 3; dep <= n; dep++) {
		memset(vis, 0, sizeof(vis));
		dfs(1, 0, 0, 0);
	}
	printf("%lld\n", ans);
	return 0;
}
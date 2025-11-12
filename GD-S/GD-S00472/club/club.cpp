#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

int T, n, a[100005][4], cnt[4], mxp[100005], dmx[100005];
vector<int> g[4];

void work() {
	n = read(), memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= 3; i++) g[i].clear();
	for (int i = 1; i <= n; i++) scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		mxp[i] = 0, dmx[i] = 0;
		for (int j = 1; j <= 3; j++) if (a[i][mxp[i]] <= a[i][j]) mxp[i] = j;
		for (int j = 1; j <= 3; j++) if (j != mxp[i] && a[i][dmx[i]] <= a[i][j]) dmx[i] = j;
		ans += a[i][mxp[i]], g[mxp[i]].push_back(i);
	}
	for (int i = 1; i <= 3; i++) if ((int)g[i].size() > n / 2) {
		sort(g[i].begin(), g[i].end(), [](int x, int y) { return a[x][mxp[x]] - a[x][dmx[x]] < a[y][mxp[y]] - a[y][dmx[y]]; });
		for (int j = 0; j < (int)g[i].size() - n / 2; j++) ans -= a[g[i][j]][mxp[g[i][j]]] - a[g[i][j]][dmx[g[i][j]]];
	}
	return printf("%d\n", ans), void();
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--) work();
	return 0;
}

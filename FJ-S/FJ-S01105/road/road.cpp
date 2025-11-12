#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 500;
struct node {
	int x, y, z;
	friend bool operator < (const node a, const node b) {
		return a.z < b.z;
	}
} edge[2 * M], edge2[2 * M];
int aed[15][(int)1e4 + 500], C[15];
int fa[(int)1e4 + 400];
int cnt;
int findd(int x) {
	return fa[x] == x ? 
	x : fa[x] = findd(fa[x]);
}
void join(int x, int y) {
	fa[y] = x;
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long ans = 1e18;
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[i] = (node) {u, v, w};
		edge2[i] = edge[i];
	}
	cnt = m;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &C[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &aed[i][j]);
		}
	}
	for (int i = 0; i < (1 << k); i++) {
		cnt = m;
		for (int j = 1; j <= cnt; j++) {
			edge[j] = edge2[j];
		}
		long long lans = 0;
		for (int j = 1; j <= k; j++) {
			if (i & (1 << (j - 1))) {
				lans += C[j];
				for (int l = 1; l <= n; l++) {
					edge[++cnt] = (node) {n + j, l, aed[j][l]};
				}
			}
		}
		sort(edge + 1, edge + cnt + 1);
		for (int j = 1; j <= n; j++) {
			fa[j] = j;
		}
		for (int j = 1; j <= cnt; j++) {
			int u = findd(edge[j].x), v = findd(edge[j].y);
			if (u != v) {
//				cout << edge[j].x << ' ' << edge[j].y << endl;
				join(u, v);
				lans += edge[j].z;
			}
			int tot = findd(fa[1]), cnttt = 1;
			for (int k = 2; k <= n; k++) {
				if (tot == findd(fa[k])) {
					cnttt++;
				}
			}
			if (cnttt == n) {
				break;
			}
		}
//		cout << i << ' ' << lans << endl;
		ans = min(ans, lans);
	}
	cout << ans << endl;
	return 0;
}

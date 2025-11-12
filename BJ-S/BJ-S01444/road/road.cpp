#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

namespace sub1 {
	const int N = 1e4 + 10;
	const int M = 12e6 + 10;
	
	int h[N], copyh[N], ne[M], e[M], idx;
	LL w[M];
	LL cost[N];
	bool st[N];
	LL a[15][N];
	LL cc[15];
	
	void add(int u, int v, LL W) {
		e[idx] = v;
		ne[idx] = h[u];
		w[idx] = W;
		h[u] = idx ++ ;
	}
	
	void solve(int n, int m, int k) {
		memset(h, -1, sizeof h);
		for (int i = 0; i < m; i ++ ) {
			int u, v; LL W;
			cin >> u >> v >> W;
			add(u, v, W);
			add(v, u, W);
		}
		for (int i = 0; i < k; i ++ ) {
			cin >> cc[i];
			for (int j = 1; j <= n; j ++ ) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i ++ ) copyh[i] = h[i];
		int cidx = idx;
		LL mainans = 0x3f3f3f3f3f3f3f3f;
		
		for (int c = 0; c < (1 << k); c ++ ) {
			LL ans = 0;
			for (int i = 1; i <= n; i ++ ) h[i] = copyh[i];
			idx = cidx;
			for (int i = 0; i < k; i ++ ) {
				if (c & (1 << i)) {
					ans += cc[i];
					for (int p = 1; p <= n; p ++ ) {
						for (int q = 1; q <= n; q ++ ) {
							if (p == q) continue;
							add(p, q, a[i][p] + a[i][q]);
							add(q, p, a[i][q] + a[i][p]);
						}
					}
				}
			}
			memset(cost, 0x3f, sizeof cost);
			memset(st, 0, sizeof st);
			st[1] = true;
			for (int i = h[1]; ~i; i = ne[i]) {
				cost[e[i]] = w[i];
			}
			for (int i = 1; i < n; i ++ ) {	
				LL mincost = 0x3f3f3f3f3f3f3f3f; int pos = 0;
				for (int j = 1; j <= n; j ++ ) {
					if (!st[j] && cost[j] < mincost) {
						pos = j;
						mincost = cost[j];
					}
				}
				st[pos] = true;
				ans += mincost;
				for (int j = h[pos]; ~j; j = ne[j]) {
					cost[e[j]] = min(cost[e[j]], w[j]);
				}
			}
			mainans = min(mainans, ans);
		}
		cout << mainans << endl;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	//if (k == 0)
		sub1::solve(n, m, k);
}

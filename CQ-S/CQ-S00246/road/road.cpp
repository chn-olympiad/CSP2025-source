#include <bits/stdc++.h>

#define int long long 

using namespace std;

namespace zcq_qwq {
	const int N = 10010 + 5, M = 1100000 + 5;
	
	struct node {
		int u, v, w;
	} a[M];
	
	int fa[N];
	
	int n, m, k, ans;
	
	int tot;
	
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]); 
	}
	
	void kruskal() {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= tot; i++) {
			int x = find(a[i].u), y = find(a[i].v);
			if (x != y) {
				fa[x] = y;
				ans += a[i].w;
			}
		}
	}
	
	void main() {
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++) {
			cin >> a[i].u >> a[i].v >> a[i].w;
		}
		tot = m;
		for (int i = 1; i <= k; i++) {
			int x;
			cin >> x;
			int mn = 0x3f3f3f3f3f3f3f3f, mn2 = 0x3f3f3f3f3f3f3f3f, mni = 0, mn2i = 0;
			for (int j = 1; j <= n; j++) {
				int y;
				cin >> y;
				if (y < mn) {
					mn2i = mni;
					mn2 = mn;
					mn = y;
					mni = j;
				} else if (y < mn2) {
					mn2i = j;
					mn2 = y;
				}
			}
			a[++tot] = {mni, mn2i, mn + mn2 + x};
		}
		sort(a + 1, a + tot + 1, [](node x, node y) {
			return x.w < y.w;
		});
		kruskal();
		cout << ans;
	} 
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	zcq_qwq::main();
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

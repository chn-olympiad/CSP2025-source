#include <bits/stdc++.h>

using namespace std;

int n, m, k;
struct EDGE {
	int u, v, val;
}e[10000005];
int fa[100005];
int pie[15][100005];
void init() {
	for (int i = 1; i <= n; i ++) fa[i] = i;
}

int findfa(int x) {
	if (fa[x] == x) return x;
	int fat = findfa(fa[x]);
	fa[x] = fat;
	return fat;
}


bool cmp(EDGE a, EDGE b) {
	return a.val < b.val;
}
int main ( ) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	init();
	if (k == 0) {
		for (int i = 1; i <= m; i ++) cin >> e[i].u >> e[i].v >> e[i].val;
		sort(e + 1, e + 1 + m, cmp);
		int cnt = 0;
		int ans = 0;
		for (int i = 1; i <= m && cnt <= n - 1; i ++) {
			int fax = findfa(e[i].u);
			int fay = findfa(e[i].v);
			if (fax == fay) continue;
			ans += e[i].val;
			cnt ++;
			fa[fax] = fa[fay];
		}
		cout << ans << '\n';
	} else  {
		for (int i = 1; i <= m; i ++) cin >> e[i].u >> e[i].v >> e[i].val;
		int js = m;
		for (int i = 1; i <= k; i ++) {
			int wy;
			cin >> wy;
			for (int j = 1; j <= n; j ++) cin >> pie[i][j];
			for (int o = 1; o <= n; o ++) {
				for (int p = 1; p <= n; p ++) {
					if (p == o) continue;
					e[++js].u = o, e[js].v = p, e[js].val = pie[i][o] + pie[i][p];
				}
			}
		}
		sort(e + 1, e + 1 + js, cmp);
		int cnt = 0;
		int ans = 0;
		for (int i = 1; i <= js && cnt <= n - 1; i ++) {
			int fax = findfa(e[i].u);
			int fay = findfa(e[i].v);
			if (fax == fay) continue;
			ans += e[i].val;
			cnt ++;
			fa[fax] = fa[fay];
		}
		cout << ans << '\n';
	}
	return 0;
} 
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);

/*
5 6 0
1 2 5
1 5 6
5 4 1
1 4 3
4 2 4
2 3 7

5 6 2
1 2 5
1 5 6
5 4 1
1 4 3
4 2 4
2 3 7
0 1 1 1 1 1 
0 1 1 1 1 1
*/

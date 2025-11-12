#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, m, k, arr[N], opd[N][14];

int fa[N];

struct SJC {
	int u, v, w;
} lent[N];

int fid (int x)
{
	return (fa[x] == x ? x : fa[x] = fid (fa[x]));
}

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		lent[i] = {u, v, w};
	}
	for (int i = 1; i <= k; ++i) {
		cin >> arr[i];
		for (int j = 1; j <= n; ++j) {
			cin >> opd[i][j];
		}
	}
	if (k == 0) {
		int ans = 0;
		sort (lent + 1, lent + 1 + m, [&] (const SJC &u, const SJC &v) {
			return u.w < v.w;
		});
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
		for (int i = 1; i <= m; ++i) {
			int fx = fid (lent[i].u),
				fy = fid (lent[i].v);
			if (fx == fy)
				continue ;
			fa[fx] = fy;
			ans += lent[i].w;
		}
		cout << ans << '\n';
	}
	else
		cout << 0 << '\n';
	return 0;
}

/*

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

4 4 0
1 2 2
2 3 1
1 3 3
4 3 999

*/

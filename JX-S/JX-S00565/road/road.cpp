#include <bits/stdc++.h>
#define ll long long
using namespace std;
int fa[20004], siz[20004];
struct road{
	int u, v, w;
};
vector<road> a;
bool cmp(road x, road y) {
	return x.w < y.w;
}
int b[21][10004];
int fa_find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return (fa[x] = fa_find(fa[x]));
}
ll ans;
void hb(int x, int y, int w) {
	int fx = fa_find(x), fy = fa_find(y);
	if (fx == fy) return;
	if (siz[fx] < siz[fy]) swap(fx, fy);
	fa[fy] = fx;
	siz[fx] += siz[fy];
	ans += w;
}
signed main() {
	freopen("road3.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
		siz[i] = (i <= n ? 1 : 0);
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a.push_back({u, v, w});
		sum += w;
	}
	bool flag = 1;
	for (int i = 1; i <= k; i++) {
		cin >> b[i][0];
		if (b[i][0] != 0) flag = 0;
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}
	if (k == 0) {
		sort(a.begin(), a.end(), cmp);
		for (size_t i = 0; i < a.size(); i++) {
			hb(a[i].u, a[i].v, a[i].w);
		}
		cout << ans << endl;
		return 0;
	}
	if (flag) {
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = j + 1; l <= n; l++) {
					a.push_back({j, l, b[i][j] + b[i][l]});
				}
			}
		}
		sort(a.begin(), a.end(), cmp);
		for (size_t i = 0; i < a.size(); i++) {
			hb(a[i].u, a[i].v, a[i].w);
			if (siz[fa_find(1)] == n) break;
		}
		cout << ans << endl;
		return 0;
	}
	cout << sum;
	return 0;
}
// luogu uid: 1277793
// 1-4, 5,6, 9,10, 13,14
// 40 pts

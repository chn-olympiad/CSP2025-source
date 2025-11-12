#include <bits/stdc++.h>
using namespace std;
int to[10005], a[15][10005];
struct road{
	int st, en, mon;
};
vector<road> r;
bool cmp(road x, road y) {
	return x.mon < y.mon;
};
int go(int k) {
	if (to[k] == k) {
		return k;
	}
	return go(to[k]);
}
int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		to[i] = i;
		int u, v, w;
		cin >> u >> v >> w;
		road tmp;
		tmp.st = u;
		tmp.en = v;
		tmp.mon = w;
		r.push_back(tmp);
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> c;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		} 
	}
	int ans = 0;
	if (k == 0) {
		sort(r.begin(), r.end(), cmp);
		for (int i = 0; i < r.size(); i++) {
			int u = r[i].st;
			int v = r[i].en;
			if (go(u) != v && go(v) != u) {
				cout << u << " " << v << endl;
				to[u] = v;
				ans += r[i].mon;
			}
		}
		cout << ans;
	}
	return 0;
}

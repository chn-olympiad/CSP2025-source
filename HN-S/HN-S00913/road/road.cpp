#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 1e6 + 10;

struct node {
	int x, y, z, id;
} p[kMaxN];

int fa[kMaxN], siz[kMaxN], n, m, k, ans;

bool cmp(node x, node y) {
	return x.z < y.z;
}

int F(int x) { return fa[x] == x ? x : fa[x] = F(fa[x]); }

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		fa[i] = i, siz[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		cin >> p[i].x >> p[i].y >> p[i].z, p[i].id = 0;
	}
	sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= m; i++) {
		int x = F(p[i].x), y = F(p[i].y);
		if (x != y) {
			(siz[x] < siz[y]) ? (fa[x] = y, siz[y] += siz[x]) : (fa[y] = x, siz[x] += siz[y]), ans += p[i].z;
		}
	}
	cout << ans << '\n';
	return 0;
}

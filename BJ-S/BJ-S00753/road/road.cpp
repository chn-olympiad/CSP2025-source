#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 10010;

int n, m, k, p[N];
struct Edge {
	int a, b; ll c;
	bool operator <(const Edge &W)const {
		return c < W.c;
	}
}e[1000010];
int c[15],a[15][N];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	bool A = true;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	if (k == 0) {
		sort(e + 1, e + m + 1);
		ll ans = 0;
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int i = 1; i <= m; i++) {
			int u = e[i].a, v = e[i].b;
			if(find(u) != find(v)) {
				p[find(u)] =find(v);
				ans += e[i].c;
			}
		}
		cout << ans << "\n";
		return 0; //16pts
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) A = false;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) A = false;
		}
	}
	if (A) {
		cout << 0 << "\n";
		return 0;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1200010, M = 1e4 + 20;

int n, m, k, ans, cnt, b[20], c[M][M], fa[N];

struct node {
	int x, y, w;
}a[N];

bool cmp(node x, node y) {
	return x.w < y.w;
}

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

void unionn(int x, int y) {
	int r1 = find(x);
	int r2 = find(y);
	fa[r1] = r2;
}

void kruskal() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int nx = find(a[i].x);
		int ny = find(a[i].y);
		if (nx == ny) {
			continue;
		}
		unionn(nx, ny);
		ans += a[i].w;
		cnt++;
		if (cnt >= n - 1) {
			return ;
		}
	}
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].x >> a[i].y >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> b[i];
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	kruskal();
	cout << ans;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
const int N = 10015, M = 2000005;
using namespace std;

int T;
int n, m, k;
struct uvw {
	int u, v, w;
};
bool operator<(uvw a, uvw b) {
	return a.w < b.w;
}
uvw g[M], f[M];
uvw d[M];
int p[15][N], c[15];

struct dsu {
	int b[N];
	
	int fnd(int x) {
		if (x == b[x]) return x;
		return b[x] = fnd(b[x]);
	}
	
	void mrg(int x, int y) {
		if (x > y)
			swap(x, y);
		b[fnd(x)] = fnd(y);
	}
	
	void ini(int n) {
		for (int i = 1; i <= n; i++)
			b[i] = i;
	}
} b;

bool ch[15];
int ans = 1e18;

int kru() {
	int siz = n - 1, id = n - 1;
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		d[i] = f[i];
	for (int i = 1; i <= k; i++)
		if (ch[i]) {
			siz++;
			ans += c[i];
			for (int j = 1; j <= n; j++)
				d[++id] = {n + i, j, p[i][j]};
		}
	b.ini(n + k);
	sort(d + 1, d + id + 1);
	int cnt = 0;
	for (int i = 1; i <= id; i++) {
		int u = d[i].u, v = d[i].v, w = d[i].w;
		if (b.fnd(u) == b.fnd(v))
			continue;
//		cout << u << ' ' << v << ' ' << w << endl;
		ans += w;
		b.mrg(u, v);
		cnt++;
		if (cnt == siz)
			break;
	}
	return ans;
}

int kru1() {
	int ans = 0;
	for (int i = 1; i <= m; i++)
		d[i] = g[i];
	b.ini(n);
	sort(d + 1, d + m + 1);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int u = d[i].u, v = d[i].v, w = d[i].w;
		if (b.fnd(u) == b.fnd(v))
			continue;
		ans += w;
		b.mrg(u, v);
		cnt++;
		f[cnt] = {u, v, w};
		if (cnt == n - 1)
			break;
	}
	return ans;
}

void dfs(int x) {
	if (x > k) {
		ans = min(ans, kru());
		return;
	}
	
	ch[x] = true;
	dfs(x + 1);
	ch[x] = false;
	dfs(x + 1);
	return;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		g[i] = {u, v, w};
	}
	kru1();
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> p[i][j];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4


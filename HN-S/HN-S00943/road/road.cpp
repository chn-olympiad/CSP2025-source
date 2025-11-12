#include <bits/stdc++.h>
#define int long long
#define IO(x) freopen(x ".in", "r", stdin), freopen(x ".out", "w", stdout)
#define FIO(x) freopen(x ".in", "r", stdin)

using namespace std;

const int N = 1e4 + 7;
const int M = 1e6 + 1e5 + 7;

int read() {
	int res = 0, f = 1;
	char c;
	while ((c = getchar()) < '0' || c > '9') { if (c == '-') { f = -1; } }
	while (c >= '0' && c <= '9') {
		res = (res << 3) + (res << 1) + (c ^ 48);
		c = getchar();
	}
	return res * f;
}
void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) { write(x / 10); }
	putchar(x % 10 + '0');
}

int n, m, k;
int tot;
int c[N];
int a[15][N];
int mp[N][N];
int has[15];
int used[N];
bool vis[N];
struct Edge {
	int u, v, w, t;
	bool operator < (const Edge &x) const {
		return w < x.w;
	}
};
Edge edge[M];

signed main() {
	IO("road");
	n = read(), m = read(), k = read();
	int ans = 0;
	int u, v, w;
	memset(mp, 0x7f, sizeof(mp));
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		edge[++tot] = {u, v, w, 0};
		mp[u][v] = mp[v][u] = w;
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		int _min = 1;
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
			_min = a[i][_min] <= a[i][j] ? _min : j;
		}
		
		int dis;
		for (int j = 1; j <= n; j++) {
			if (j != _min) {
				dis = a[i][j] + a[i][_min] + c[i] * !(used[i]);
				if (dis < mp[j][_min]) {
					edge[++tot] = {_min, j, a[i][j] + a[i][_min], i};
					mp[j][_min] = mp[_min][j] = dis;
					used[i]++;
				}
			}
		}
	}
	sort(edge + 1, edge + 1 + tot);
	int t = 0, tt;
	for (int i = 1; i <= m; i++) {
		u = edge[i].u, v = edge[i].v, w = edge[i].w, tt = edge[i].t;
		if (!vis[u] || !vis[v]) {
			vis[u] = vis[v] = true;
			t++;
			ans += w;
		}
		if (t >= n - 1) {
			break;
		}
	}
	for (int i = 1; i <= k; i++) { ans += c[i] * (used[i] != 0); }
	
	write(ans);
	return 0;
}

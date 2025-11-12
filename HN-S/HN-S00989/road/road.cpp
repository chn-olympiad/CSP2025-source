#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e4 + 100;
const int MAXM = 1e6 + 100;
const int MAXK = 15;
const int inf = 1ll << 60;
int n, m, k, c[MAXK], a[MAXK][MAXN], edge_size;
vector<int> now[MAXK];
int ans = inf, res = 0;
struct Edge {
	int u, v, w;
	int isy;
	
	bool operator < (const Edge &other) const {
		return w < other.w;
	}
}e[MAXM + MAXN * MAXK], ee[MAXM];

inline int read() {
	int f = 1, rd = 0; char ch = getchar();
	while (!((ch >= '0' && ch <= '9') || ch == '-')) ch = getchar();
	if (ch == '-') f = -1; else rd = ch - '0'; ch = getchar();
	while (ch >= '0' && ch <= '9') rd = rd * 10 + ch - '0', ch = getchar();
	return rd * f;
}

int fa[MAXN * MAXK];

void init() {
	for (int i = 1; i <= n + k; ++i) {
		fa[i] = i;
	}
}

int find(int x) {
	return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

void Kruskal(const bool flag) {
	res = 0;
	init();
	int cnt = n, tot = 0;
	if (flag) {
		sort(e + 1, e + edge_size + 1);
	}
	for (int i = 1; i <= edge_size; ++i) {
		if (e[i].isy == 0) continue;
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) {
			fa[fu] = fv;
			--cnt;
			res += e[i].w;
			if (flag == true) {
				ee[++tot] = e[i];
			}
		}
		if (cnt == 1) {
			return;
		}
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
		e[i].isy = 1;
	}
	
	for (int i = 1; i <= k; ++i) {
		c[i] = read();
		for (int j = 1; j <= n; ++j) {
			a[i][j] = read();
		}
	}
	
	edge_size = m;
	Kruskal(true);
	
	for (int i = 1; i < n; ++i) {
		e[i] = ee[i];
		e[i].isy = 0;
	}
	
	int Tot = n - 1;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			e[++Tot] = {n + i, j, a[i][j], i};
		}
	}
	
	sort(e + 1, e + Tot + 1);
	for (int i = 1; i <= Tot; ++i) {
		now[e[i].isy].push_back(i);
		e[i].isy = 0;
	}
	edge_size = Tot;
	int yn = n;
	for (int mask = 0; mask < (1 << k); ++mask) {
		for (int i = 1; i <= Tot; ++i) {
			e[i].isy = 0;
		}
		int Add = 0;
		for (int i = 1; i <= k; ++i) {
			if (mask & (1 << (i - 1))) {
				++n;
				Add += c[i];
				for (int j = 0; j < now[i].size(); ++j) {
					int no = now[i][j];
					e[no].isy = 1;
				}
			}
		}
		for (int j = 0; j < now[0].size(); ++j) {
			int no = now[0][j];
			e[no].isy = 1;
		}
		Kruskal(false);
		ans = min(ans, res + Add);
		n = yn;
	}
	
	cout << ans << '\n';
}


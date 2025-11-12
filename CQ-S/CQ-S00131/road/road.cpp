#include<bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define PLI pair<LL, int>
#define PII pair<int, int>
using namespace std;
const int N = 1e4, M = 1e6, K = 10;
const LL INF = 5e15;
int siz[N + K + 5], p[N + K + 5];
struct UF {
	void init(int n) {
		for (int i = 1; i <= n; i++) siz[i] = 1, p[i] = i;
	}
	int Find(int x) {
		return (x == p[x] ? x : p[x] = Find(p[x]));
	}
	void Union(int x, int y) {
		x = Find(x); y = Find(y);
		if (x == y) return;
		if (siz[x] > siz[y]) swap(x, y);
		p[x] = y;
		siz[y] += siz[x];
	}
}uf;
int n, m, k;
LL v[K + 5], ans = INF;
PLI b[K + 5][N + 5];
struct edge {
	int u, v, tag; LL w;
	bool operator < (const edge &o) const {
		return w < o.w;
	}
}a[M + 5], c[N * (K + 2) + 5], f[1025][N + K + 2]; 
bool cmp(const edge x, const edge y) {
	return x.tag > y.tag;
}
LL kruscal(edge *e, int ce, int cp) {
	uf.init(cp); LL ret = 0;
	for (int i = 1; i <= ce; i++) {
		if (uf.Find(e[i].u) != uf.Find(e[i].v)) {
			ret += e[i].w;
			e[i].tag = 1;
			uf.Union(e[i].u, e[i].v);
			if (siz[uf.Find(e[i].u)] == cp) break;
		}
	}
	return ret;
}
int lowbit(int i) { return i & -i; }
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	sort(a + 1, a + m + 1);
	ans = kruscal(a, m, n);
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i < n; i++) f[0][i] = a[i], f[0][i].tag = 0;
	sort(f[0] + 1, f[0] + n);
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j].first; b[i][j].second = j;
		}
		sort(b[i] + 1, b[i] + n + 1);
	}
	for (int z = 1; z < (1 << k); z++) {
		int cnt = 0, t = 1; LL sum = 0;
		for (int i = 1; i <= k; i++) if (((z >> (i - 1)) & 1) == 1) {
			sum += v[i];
			cnt++;
		}
		int lst = z - lowbit(z);
//		if (lst) for (int i = 1; i < n + cnt - 1; i++) c[i] = f[lst][i];
//		else for (int i = 1; i < n; i++) c[i] = a[i], c[i].tag = 0;
//		t = n + cnt - 1;
		t = n + cnt - 2 + n;
		for (int i = 1; i <= k; i++) if (((z >> (i - 1)) & 1) == 1) {
			int l = 1, r = 1;
			for (int j = 1; j <= t; j++) {
				if ((r > n) || (l <= n + cnt - 2 && f[lst][l].w <= b[i][r].first)) {
					c[j] = f[lst][l];
					l++;
				} else {
					c[j] = {cnt + n, b[i][r].second, 0, b[i][r].first};
					r++;
				}
			}
			break;
		}
//		sort(c + 1, c + t + 1);
		sum += kruscal(c, t, cnt + n);
		ans = min(ans, sum);
		vector<int> pos(1);
//		sort(c + 1, c + t, cmp);
		for (int i = 1; i <= t; i++) if (c[i].tag) pos.push_back(i);
		for (int i = 1; i < cnt + n; i++) f[z][i] = c[pos[i]], f[z][i].tag = 0;
	}
	cout << ans << "\n";
}
signed main() {
//	freopen("road4.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}


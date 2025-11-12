#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e6 + 10;
const int N = 2e4 + 10;
const int K = 15;
const int mod = 998244353;

int n, m, k, cnt;

int a[K][N], c[K];

struct edge{int f, t, v;}ed[M];

bool cmp (edge a, edge b) { return a.v < b.v;}
edge min (edge a, edge b) { return a.v < b.v ? a : b; }

vector <edge> e, t;

int fa[N], tot;

int fnd (int p) {return fa[p] == p ? p : fa[p] = fnd(fa[p]);}
bool uni (int x, int y) {
	int fx = fnd(x), fy = fnd(y);
	if (fx == fy) return 0;
	fa[fx] = fy, tot --; return 1;
}

int kruskal (int n) {
	tot = n;
	for (int i = 1 ; i <= n ; i ++) fa[i] = i;
	int l = 0, ll = 0, ans = 0;
	while (1) {
		edge now;

		if (l > e.size()) now = t[ll], ll ++;
		else if (ll > t.size()) now = e[l], l ++;
		else if (e[l].v <= t[ll].v) now = e[l], l ++;
		else now = t[ll], ll ++;

		auto [f, t, v] = now;
		if (uni(f, t)) {
			ans += v;
			if (tot == 1) break;
		}
	}
	return ans;
}

const int B = 1024, KB = 10;

vector <edge> buf[B + 10];
vector <edge> tmp;
void sort (vector <edge> &vec) { 
	int mx = 0;
	for (auto [f, t, v] : vec) mx = max(mx, v);
	
	for (int i = 0 ; i <= 2 ; i ++) {
		tmp.clear();
		int k = KB * i;
		for (auto p : vec) buf[((p.v >> k) & (B - 1))].push_back(p);
		for (int i = 0 ; i < B ; i ++) {
			for (auto x : buf[i]) tmp.push_back(x);
			buf[i].clear();
		}
		vec = tmp;
	}
}

void solve () {
	cin >> n >> m >> k;

	for (int i = 1, f, t, v ; i <= m ; i ++) 
		cin >> f >> t >> v, ed[i] = {f, t, v};
	
	for (int i = 1 ; i <= k ; i ++) {
		cin >> c[i];
		for (int j = 1 ; j <= n ; j ++) cin >> a[i][j];
	}

	sort(ed + 1, ed + 1 + m, cmp);

	int ans = 0;

	tot = n;
	for (int i = 1 ; i <= n ; i ++) fa[i] = i;
	
	for (int i = 1 ; i <= m ; i ++) {
		auto [f, t, v] = ed[i];
		if (uni(f, t)) {
			e.push_back({f, t, v}), ans += v;
			if (tot == 1) break;
		}
	}

	for (int s = 1 ; s < (1 << k) ; s ++) {
		int pre = 0; 
		t.clear(), cnt = n;

		for (int i = 1 ; i <= k ; i ++)
			if (s & (1 << (i - 1))) pre += c[i];
		
		if (pre >= ans) continue;
		
		for (int i = 1 ; i <= k ; i ++) {
			if (s & (1 << (i - 1))) {
				cnt ++;
				for (int j = 1 ; j <= n ; j ++) 
					t.push_back({cnt, j, a[i][j]});
			}
		}
		
		// sort(t.begin(), t.end(), cmp);
		sort(t);

		ans = min(ans, pre + kruskal(cnt));
	}

	cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int t = 1;
	// cin >> t;

	while (t --) solve();
}

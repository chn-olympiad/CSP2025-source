#include <bits/stdc++.h>
#define int long long
#define USE_FREOPEN
//#define MUL_TEST
#define FILENAME "road"
using namespace std;
int fa[100005];
int a[15][100005];
int c[15], built[15], dis2[15];
int dis[100005], use[100005];
set<pair<int, int> > stc[15], st;
vector<pair<int, int> > G[100005];

struct edg {
	int u, v, w;
	const bool operator<(const edg &x) const {
		return w < x.w;
	}
} edgs[2000005];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int u, int v) {
	int x = find(u), y = find(v);
	if (x == y) return;
	fa[x] = y;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			cin >> edgs[i].u >> edgs[i].v >> edgs[i].w;
		}
		sort(edgs + 1, edgs + m + 1);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		int cnt = 0, ans = 0;
		for (int i = 1; i <= m; i++) {
			int u = edgs[i].u, v = edgs[i].v, w = edgs[i].w;
			if (find(u) == find(v)) continue;
			merge(u, v);
			ans += w, cnt++;
			if (cnt == n - 1) break;
		}
		cout << ans << '\n';
	} else {
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
		for (int i = 1; i <= k; i++) {
			cin >> c[i];
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		memset(dis, 0x3f, sizeof(dis));
		int INF = dis[0];
		use[1] = 1;
		dis[1] = 0;
		for (auto it : G[1]) {
			int v = it.first, w = it.second;
			dis[v] = min(dis[v], w);
		}
		for (int i = 2; i <= n; i++) {
			st.insert(make_pair(dis[i], i));
		}
		for (int i = 1; i <= k; i++) {
			dis2[i] = c[i] + a[i][1];
			for (int j = 2; j <= n; j++) {
				stc[i].insert(make_pair(a[i][j], j));
			}
		}
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			auto itd = st.begin();
			int id = itd->second, val = itd->first;
			int id2 = 0, val2 = LLONG_MAX, usec = 0;
			for (int j = 1; j <= k; j++) {
				auto it = stc[j].begin();
				int idc = it->second, valc = it->first;
				valc += dis2[j];
				if (val2 > valc) {
					id2 = idc;
					val2 = valc;
					usec = j;
				}
			}
			if (val > val2) {
//				cout << id2 << ' ' << val2 << ' ' << usec << '\n';
				st.erase(make_pair(dis[id2], id2));
				use[id2] = 1;
				dis[id2] = 0;
				ans += val2;
				for (int j = 1; j <= k; j++) {
					stc[j].erase(make_pair(a[j][id2], id2));
					dis2[j] = min(dis2[j], c[j] + a[j][id2]);
				}
				if (!built[usec]) {
					built[usec] = 1;
					dis2[usec] = 0;
				}
				for (auto it : G[id2]) {
					int v = it.first, w = it.second;
					if (dis[v] > w) {
						st.erase(make_pair(dis[v], v));
						dis[v] = w;
						st.insert(make_pair(dis[v], v));
					}
				}
			} else {
				st.erase(itd);
//				cout << id << ' ' << val << '\n';
				use[id] = 1;
				dis[id] = 0;
				ans += val;
				for (int j = 1; j <= k; j++) {
					stc[j].erase(make_pair(a[j][id], id));
					dis2[j] = min(dis2[j], c[j] + a[j][id]);
				}
				for (auto it : G[id]) {
					int v = it.first, w = it.second;
					if (dis[v] > w) {
						st.erase(make_pair(dis[v], v));
						dis[v] = w;
						st.insert(make_pair(dis[v], v));
					}
				}
			}
		}
		cout << ans << '\n';
	}
}

signed main() {
	#ifdef USE_FREOPEN
		freopen(FILENAME ".in", "r", stdin);
		freopen(FILENAME ".out", "w", stdout);
	#endif

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int _ = 1;
	#ifdef MUL_TEST
		cin >> _;
	#endif
	while (_--)
		solve();

	_^=_;
	return (0^_^0);
}


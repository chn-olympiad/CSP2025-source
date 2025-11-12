#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e4 + 20;
const int M = 3e6 + 20; 
const int K = 25;

struct Edge {
	int u, v, w;
} edge[M], T[M];

int n, m, k;
int a[K][N], c[K];
int fa[N];

vector<pair<int, int> > linker[N];

void add(int x, int y, int w) {
	linker[x].push_back({ y, w });
}

int Find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = Find(fa[x]);
}

void merge(int x, int y) {
	int xx = Find(x), yy = Find(y);
	fa[xx] = yy;
}

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int cnt;
ll kruskal(int dn) {
	for (int i = 1; i <= 3 * n; i++) fa[i] = i;
	
//	cout << "------------------------\n";
	sort(edge + 1, edge + cnt + 1, cmp);
	
	ll res = 0, sum = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
		
//		cout << u << " " << v << " " << w << endl;
		if (Find(u) != Find(v)) {
			merge(u, v);
			res += w;
			sum++;
		}
		
		if (sum == dn - 1) {
//			cout << res << endl;
			return res;
		}
	}
	
	if (sum != dn - 1) {
//		cout << 1e9 << endl;
		return LONG_LONG_MAX;
	}
	
//	cout << res << endl;
	return res;
}

ll ans;
bool vis[N];
vector<int> vec;

void dfs(int x) {
	if (x == k + 1) {
		if (vec.size() == 0) return ;
		
		cnt = m;
		for (int i = 1; i <= m; i++)
			edge[i] = T[i];
		
		for (auto i : vec) {
			edge[++cnt] = { i + n, i + n + n, c[i] };
			for (int j = 1; j <= n; j++)
				edge[++cnt] = { i + n, j,  a[i][j] };
		}
		
		ans = min(ans, kruskal(n + 2 * vec.size()));
//		cout << vec.size() << endl;
		
		return ;
	}
	
	vec.push_back(x);
	dfs(x + 1);
	vec.pop_back();
	
	dfs(x + 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			
			edge[i] = { u, v, w };
		}
		
		cout << kruskal(n) << endl;
		return 0;
	}
	
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		
		add(u, v, w), add(v, u, w);
		edge[i] = { u, v, w };
		T[i] = { u, v, w };
	}
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	} 
	
	cnt = m, ans = kruskal(n);
//	cout << ans << endl;
	dfs(1);
	
	cout << ans << endl;
//	cout << clock() / 1000 << endl;
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

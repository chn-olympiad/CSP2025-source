#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kN = 1e4 + 5, kM = 1e6 + 5;
 
struct Edges {
	int x, y;
	ll w;
} edge[kM]; 

bool use[kN];
int pos[kN][2];
ll mini[kN][11], dis[11][kN], c[11], rec[kN][11], e[kN], l[kN][11][2], r[kN][11], col[kN][11], ans;
int fath[kN];
int n, m, k; 

int F (int x) {
	return fath[x] = fath[x] == x ? x : F (fath[x]);
}

void Kruskal () {
	for (int i = 1; i <= n; ++i) {
		fath[i] = i;
		for (int j = 1; j <= k; ++j) {
			mini[i][j] = dis[j][i];
		}
	}
	
	int tot = 0;
	for (int i = 1; i <= m && tot < n - 1; ++i) {
		int x = F (edge[i].x), y = F (edge[i].y);
		if (x != y) {
			++tot;
			fath[x] = y;			
			pos[tot][0] = x, pos[tot][1] = y;
			e[tot] = edge[i].w;
			ans += e[tot];
			for (int j = 1; j <= k; ++j) {
				l[tot][j][0] = mini[x][j], l[tot][j][1] = mini[y][j];
				rec[tot][j] = mini[x][j] + mini[y][j];
				mini[y][j] = min (mini[y][j], mini[x][j]);
			}
		}
	}
}

ll res, cnt;
void DFS (int cur) {
	if (cur == k + 1) {
		if (cnt == 0) {
			return ;
		}
		res = cnt;
		fill (use + 1, use + 1 + n, 0);
		for (int i = 1; i < n; ++i) {
			ll tmp = r[i][k];
//			cout << pos[i][0] << ' ' << pos[i][1] << ' ';
//			cout << r[i][k] << ' ' << col[i][k] << '\n';
			if (use[pos[i][0]]) tmp -= l[i][col[i][k]][0];
			if (use[pos[i][1]]) tmp -= l[i][col[i][k]][1];
//			cout << l[i][col[i][k]][0] << ' ' << l[i][col[i][k]][1] << ' ' << tmp << '\n';
//			cout << e[i] << ' ' << tmp << '\n';
			res += min (e[i], tmp);
			if (tmp <= e[i]) use[pos[i][1]] = 1;
			use[pos[i][1]] |= use[pos[i][0]];
		}
//		cout << res << "******\n";
		ans = min (ans, res);
		return ;
	}
	for (int i = 1; i < n; ++i) {
		r[i][cur] = r[i][cur - 1];
		if (r[i][cur] > rec[i][cur]) {
			r[i][cur] = rec[i][cur];
			col[i][cur] = cur;
		}
	}
	cnt += c[cur];
	DFS (cur + 1);
	cnt -= c[cur];
	for (int i = 1; i < n; ++i) {
		r[i][cur] = r[i][cur - 1];
		col[i][cur] = col[i][cur - 1];
	}
	DFS (cur + 1);
} 

int main () {
  freopen ("road.in", "r", stdin);
  freopen ("road.out", "w", stdout);
  ios::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);
  
  cin >> n >> m >> k;
  for (int i = 1, x, y; i <= m; ++i) {
  	ll w;
  	cin >> x >> y >> w;
  	edge[i].x = x, edge[i].y = y, edge[i].w = w;
	}
	bool flag = 1; 
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		flag &= (c[i] == 0);
		for (int j = 1; j <= n; ++j) {
			cin >> dis[i][j];
			flag &= (dis[i][j] == 0);
		}
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	
	sort (edge + 1, edge + 1 + m, [](Edges x, Edges &y) {
		return x.w < y.w;
	});
	Kruskal ();
	// record
	
	for (int i = 1; i < n; ++i) {
		r[i][0] = 1e18;
	}
	DFS (1);
	
	cout << ans;
  return 0;
}


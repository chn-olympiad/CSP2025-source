#include <bits/stdc++.h>
using namespace std;
#define pii pair < int , int >
using namespace std;

const int N = 1e4 + 1e3 + 5;
int n, m, k;
vector < pii > g[N];
vector < pii > e[N];
int wei[N]; // µ„»®
int ans;
int f[N];

int find (int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

void merge (int u, int v) {
	int fu = find(u);
	int fv = find(v);

	if (fu == fv)
		return ;

	f[ fu ] = fv;
}

bool comp (pii x, pii y) {
	return x.second < y.second;
}

void Kruskal (int s) {
	queue < int > q;

	q.push(s);

	while ( !q.empty() ) {
		int u = q.front();
		q.pop();
		
		sort(g[u].begin(), g[u].end(), comp);

		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first;
			int w = g[u][i].second;

			if (find(u) == find(v))
				continue;

			merge(u, v);
			q.push(v);
			ans += w;
			e[u].push_back({v, w});
			e[v].push_back({u, w});

			break;
		}
	}
}

int pro (int x) {
	for (int i = n+1; i <= n+k; i++) {
		if (e[i].size() == 1) {
			x -= e[i][0].second;
		}
		else {
			x -= (e[i].size()-1) * wei[i];
		}
	}
	
	return x;
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		int u, v, w;

		cin >> u >> v >> w;

		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	for (int i = 1; i <= k; i++) {
		cin >> wei[n + i];

		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;

			g[i+n].push_back({j, w + wei[n+i]});
			g[j].push_back({i+n, w + wei[n+i]});
		}
	}

	int Ans = 2e9;
	for (int i = 1; i <= n + k; i++) {
		for (int j = 1; j <= n+k+5; j++)
			f[j] = j;
		ans = 0;
		Kruskal(i);
		ans = pro(ans);
		
		Ans = min(Ans, ans);
	}

	cout << Ans;
	return 0;
}

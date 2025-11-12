#include <queue>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long int
#define ui unsigned int
#define ull unsigned long long int

using std::cout; using std::cin;

const int N = 1e4 + 25, M = 1e6 + 10, inf = 0x3f3f3f3f;

ui n, m, k;
ui all; 						// all nodes number
struct Node {
	ui to;
	ui w;
};
// g[i][j]: the No.j edge of the No.i node
std::vector<Node> g[N];
ui wv[15];
bool cmpa(const Node &a, const Node &b) {
	return a.w < b.w;
}

ui f[N];
ui find(ui x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(ui a, ui b) {
	f[find(a)] = f[find(b)];
}

bool check() {
	for (ui i = 2; i <= n; ++i)
		if (find(i) != find(i - 1)) return false;
	return true;
}

bool flag;
ull ans = UINT_MAX;
void prim(ui id, ull money) {
	if (id > all) return ;
	if (id > n) {
		if (check()) {
			ans = money;
			flag = true;
		}
		return ;
	}

	for (ui i = 0; i < g[id].size(); ++i) {
		ui v = g[id][i].to, w = g[id][i].w;
		if (find(v) == find(id)) continue;
		if (v > n) {
			// if v is a village
			// we will skip it
			continue;
		} else {
			// if v is a city
			// we will choose the node has the least weight of id->it+it->v
			ull min = UINT_MAX;
			ui min_ix = n + 1;
			for (ui j = n + 1; j <= n + 15; ++j) {
				ui distance = g[j][id - 1].w + g[j][v - 1].w;
				if (distance < min) {
					min = distance;
					min_ix = j;
				}
			}


			ull money_city = w;
			ull money_village = min;

			// and compare the weight of id->min_ix+min_ix->v and the weight of id->v
			if (money_city < money_village) {
				// choose the road which is id->v
				merge(id, v);
				// go to v
				prim(v, money + money_city);
			} else {
				// choose the road which is id->min_ix->v
				merge(id, min_ix);
				merge(min_ix, v);
				// go to v
				prim(v, money + min);
			}
		}
		if (flag) return ;
	}
}

void solveA() {
	all = n + k;
	for (ui i = 1; i <= m; ++i) {
		ui u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (ui i = 1; i <= k; ++i) {
		cin >> wv[i];
		for (ui j = 1; j <= n; ++j) {
			ui w;
			cin >> w;
			g[n + i].push_back({j, w});
			g[j].push_back({n + i, w});
		}
	}
	for (ui i = 1; i <= all; ++i) {
		std::sort(g[i].begin(), g[i].end(), cmpa);
	}

	flag = false;
	prim(1, 0);

	cout << ans << '\n';
}

struct Edge {
	ui u, v;
	ui w;
};
std::vector<Edge> e;
bool cmpk(const Edge &a, const Edge &b) {
	return a.w < b.w;
}

ull ansk;
void kruskal() {
	for (ui i = 0; i < e.size(); ++i) {
		ui u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) == find(v)) continue;
		merge(u, v);
		//cout << u << "->" << v << "(" << w << ")" << " has chose.\n";
		ansk += w;
	}
}
void solvek0() {
	for (ui i = 1; i <= m; ++i) {
		ui u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
		e.push_back({v, u, w});
	}
	for (ui i = 1; i <= k; ++i) {
		cin >> wv[i];
		for (ui j = 1; j <= n; ++j) {
			ui w;
			cin >> w;
			e.push_back({j, n + i, w});
			e.push_back({n + i, j, w});
		}
	}

	std::sort(e.begin(), e.end(), cmpk);

	kruskal();

	cout << ansk << '\n';
}

int main() {

	std::ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for (ui i = 1; i <= n; ++i) f[i] = i;
	if (k == 0) {
		solvek0();
	} else {
		solveA();
	}

	return 0;
}







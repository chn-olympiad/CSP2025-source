#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1e4 + 10;

int n, m, k;

struct OEdge{
	int u, v, w;
	bool operator < (const OEdge &b) {
		return w < b.w;
	}
};

vector<OEdge> OG;

int create[20];
int city[15][maxn];

vector<OEdge> lis; // w, id

LL res = 1e18;

int fa[maxn + 30];

inline void clear() {
	lis.clear();
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
}

inline void add_edge(int u, int v, int w) {
	lis.push_back({u, v, w});
}

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

inline void merge(int u, int v) {
	fa[find(u)] = find(v);
}


void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		OG.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", create + i);
		for (int j = 1; j <= n; j++) {
			scanf("%d", city[i] + j);
		}
	}
	
	int ALL = (1 << k) - 1;
	for (int S = 0; S <= ALL; S++) {
		clear();
		LL sum = 0;
		for (int p = 0; p < k; p++) if ((S >> p) & 1) {
			for (int i = 1; i <= n; i++) {
				add_edge(n + p + 1, i, city[p+1][i]);
			}
			sum += create[p+1];
		}
		for (auto tmp: OG) {
			add_edge(tmp.u, tmp.v, tmp.w);
		}
		sort(lis.begin(), lis.end());
		for (auto edge: lis) {
			int u = edge.u, v = edge.v, w = edge.w;
			if (find(u) == find(v)) continue;
			sum += w;
			merge(u, v);
		}
		res = min(res, sum);
	}
	cout << res << endl;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	solve(); // O(m * 2^k)
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

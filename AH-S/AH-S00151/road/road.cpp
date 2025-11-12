#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define DLN(x) cout << #x << "\t = " << x << '\n';
#define CDLN(x, l, r) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << (x[_IDX]) << ' '; cout << "]\n";
#define CCDLN(x, l, r, what) cout << #x << "\t = [ "; for (int _IDX = l; _IDX <= r; _IDX ++) cout << (what) << ' '; cout << "]\n";

template <typename T>
using vec = vector<T>;

using ll = long long;

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int KN = 15;
struct Edge {
	int u, v, w;
} es[N];

int K, n, m;

int fa[N];

int c[KN];
int a[KN][N];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	fa[fx] = fy;
}

int kruskal() {
	int res = 0;
	sort(es + 1, es + 1 + m, [](Edge a, Edge b) {
		return a.w < b.w;
	});

	for (int i = 1; i <= m; i ++) {
		int u = es[i].u;
		int v = es[i].v;
		int w = es[i].w;
		int fu = find(u), fv = find(v);

		if (fu != fv) {
			unite(fu, fv);
			res += w;			
		} 
	}

	return res;
}

void solve1() {
	int res = kruskal();
	cout << res << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &K);

	for (int i = 1; i <= n + K; i ++) fa[i] = i;

	for (int i = 1, u, v, w; i <= m; i ++) {
		scanf("%d%d%d", &u, &v, &w);
		es[i] = { u, v, w };
	}

	for (int i = 1; i <= K; i ++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &a[i][j]);
		}
	}


	
	solve1();



	return 0;
}
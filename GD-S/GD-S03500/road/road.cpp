#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define int ll

const int N = 10000 + 100;
const int EN = 1000000 + 100;
const int M = 50 + 10;
const int inf = 1000000007;
using namespace std;

int read () {
	int x = 0, k = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') k = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * k;
}

struct Edge { int u, v, w; } E[EN << 1];
int n, m, k, cnt; long long ret;
int c[M], a[M][N];

int fa[N << 1]; vector<Edge> V, G;
int Find (int x) {
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}

signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; ++i) u = read(), v = read(), w = read(), E[++cnt] = (Edge{ u, v, w });
	for (int i = 0; i < k; ++i) { c[i] = read(); for (int j = 1; j <= n; ++j) a[i][j] = read(); }
	sort(E + 1, E + 1 + cnt, [](const Edge &A, const Edge &B){ return A.w < B.w; });

	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= cnt; ++i) {
		Edge U = E[i]; int u = U.u, v = U.v, w = U.w;
		int x = Find(u), y = Find(v); 
		if (x == y) continue;
		V.push_back(U), fa[x] = y, ret += w;
	}

	int All = (1 << k) - 1, nn = n + k;
	for (int S = 0; S <= All; ++S) {
		long long ret0 = 0; G.clear(); for (auto v: V) G.push_back(v);
		for (int _ = 0; _ < k; ++_) if ((S >> _) & 1) { ret0 += c[_]; for (int i = 1; i <= n; ++i) G.push_back((Edge { i, n + 1 + _, a[_][i] })); }
		for (int i = 1; i <= nn; ++i) fa[i] = i;
		sort(G.begin(), G.end(), [](const Edge &A, const Edge &B){ return A.w < B.w; });
		for (Edge U: G) {
			int u = U.u, v = U.v, w = U.w;
			int x = Find(u), y = Find(v); 
			if (x == y) continue;
			fa[x] = y, ret0 += w;
		}
		ret = min(ret, ret0);
	}

	cout << ret << endl;
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

weiyuqi 15:49
*/


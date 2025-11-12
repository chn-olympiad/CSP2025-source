#include <bits/stdc++.h>

#define i64 long long

using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || '9' < ch) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') x = x * 10 + (ch - '0'), ch = getchar();
	return x * f;
}

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 15;
const int P = 1.1e5 + 10;

int n, m, k, tot;
int c[K], a[K][N];
int f[N];
int Ls[P], Top;
struct node {
	int u, v, w;
}p[M], r[N], b[K][N], Fin[P];
unordered_map<int, int> q;
basic_string<pair<int, int> > E[P];

inline bool cmp(const node &a, const node &b) {
	return a.w < b.w;
}

inline int Find(int x) {
	if (f[x] != x) f[x] = Find(f[x]);
	return f[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i ++) {
		p[i].u = read();
		p[i].v = read();
		p[i].w = read();
	}
	
	for (int i = 0; i < k; i ++) {
		c[i] = read();
		for (int j = 1; j <= n; j ++) a[i][j] = read(), Ls[++ Top] = a[i][j];
		for (int j = 1; j <= n; j ++) b[i][j] = (node){j, n + 1 + i, a[i][j]};
	}
	
	sort(p + 1, p + 1 + m, cmp);
	
	for (int i = 1; i <= n; i ++) f[i] = i;
	for (int i = 1; i <= m; i ++) {
		int fx = Find(p[i].u), fy = Find(p[i].v);
		if (fx != fy) {
			f[fx] = fy;
			r[++ tot] = p[i];
			Ls[++ Top] = p[i].w;
		}
	} 
	
	sort(Ls + 1, Ls + 1 + Top);
	Top = unique(Ls + 1, Ls + 1 + Top) - Ls - 1;
	for (int i = 1; i <= Top; i ++) q[Ls[i]] = i;
	
	for (int i = 1; i <= tot; i ++) r[i].w = q[r[i].w];
	for (int i = 0; i < k; i ++)
		for (int j = 1; j <= n; j ++)
			b[i][j].w = q[b[i][j].w];
	
	i64 Ans = 1e18;
	for (int id = 0; id < (1 << k); id ++) {
		i64 Sum = 0;
		for (int i = 1; i <= n + k; i ++) f[i] = i;
		for (int i = 1; i <= tot; i ++) E[r[i].w].push_back(make_pair(r[i].u, r[i].v));
		for (int j = 0; j < k; j ++) {
			if (id >> j & 1) {
				Sum += c[j];
				for (int i = 1; i <= n; i ++) {
					E[b[j][i].w].push_back(make_pair(b[j][i].u, b[j][i].v));
				}
			}
		}
		for (int i = 1; i <= Top; i ++) {
			int Lim = (int)E[i].size(); 
			for (int j = 0; j < Lim; j ++) {
				int fx = Find(E[i][j].first), fy = Find(E[i][j].second);
				if (fx != fy) {
					f[fx] = fy;
					Sum += Ls[i];
				}
			}
			E[i].clear();
		}
		Ans = min(Ans, Sum);
	}
	
	printf("%lld", Ans);
	
	return 0;
} 
//i64

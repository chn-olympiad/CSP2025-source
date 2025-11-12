#include <bits/stdc++.h>

using namespace std;
using PII = pair < int, int>;
const int N = 2e6 + 30;
const int M = 1e4 + 10;
const int INF = 0x3f3f3f3f;

inline int read(char ch = getchar(), int x = 0, int f = 1) {
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch - '0';
	return x * f;
}

int T = 1;
int n, m, k;
int fa[N];
int tot = 0;
int cnt;

struct node {
	int u, v, w;
};

node e[N];

int find(int x) {
	return (fa[x] == x) ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[x] = y;
}

inline void SeaWave() {
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; ++i) 
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	sort(e + 1, e + n + 1, [] (node a, node b) {
		return a.w < b.w;	
	});
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fx = find(u), fy = find(v);
		if (fx == fy) continue;
		merge(fx, fy);
		tot += w;
		if (++cnt == n - 1) break;
	}
	for (int i = n + 1; i <= n + k; ++i) {
		e[i].w = read();
		for (int j = 1; j <= n; ++j) {
			e[i].u = i, e[i].v = j, e[i].w = read();
		}
	}
	cout << tot << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
//	T = read();
	while (T--)
		SeaWave();
	return 0;
}

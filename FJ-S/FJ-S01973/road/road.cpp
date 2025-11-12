#include <bits/stdc++.h>
#define int long long

template<typename T> void read(T &x) {
	x = 0; char s = getchar();
	for (; !isdigit(s); ) s = getchar();
	for (; isdigit(s); s = getchar()) x = (x << 3) + (x << 1) + s - '0';
}

template<typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }
template<typename T> void ckadd(T &x, T y, T p) { x = (x + y) % p; }
template<typename T> void ckmul(T &x, T y, T p) { x = (x * y) % p; }

const int N = 1e5 + 100;
const int M = 1e6 + 100;

struct Edge {
	int x, y, w, cost, state;
	bool operator < (const Edge &rhs) const {
		return cost + w < rhs.cost + rhs.w;
	}
} E[2 * M];

int f[N], lnk[13][N], Cnt[N];
int n, m, k, ans;

int F(int x) { return f[x] == x ? x : f[x] = F(f[x]); }

bool CmpA(Edge A, Edge B) { return A.cost + A.w < B.cost + B.w; }
bool CmpB(Edge A, Edge B) { return A.cost < B.cost; }
bool CmpC(Edge A, Edge B) { return A.w < B.w; }

int Kruskal(int __) {
	int res = 0;
	if (__ == 1) std::sort(E + 1, E + m + 1, CmpA);
	else if (__ == 2) std::sort(E + 1, E + m + 1, CmpB);
	else std::sort(E + 1, E + m + 1, CmpC);
	for (int i = 1; i <= n + k; i ++) f[i] = i, Cnt[i] = 0;
	for (int i = 1, now = 0, cnt = 0; i <= m; i ++) {
		int x = E[i].x, y = E[i].y, w = E[i].w, cost = E[i].cost, state = E[i].state;
		int X = F(x), Y = F(y); if (X == Y) continue;
		f[X] = Y;
		if (x <= n && ++ Cnt[x] == 1) cnt ++;
		if (y <= n && ++ Cnt[y] == 1) cnt ++;
//		printf("%lld %lld %lld %lld %lld\n", x, y, w, cost, state);
		if (!(now & state)) res += w + cost, now |= state;
		else res += w;
		if (cnt == n) break;
	}
//	printf("\n");
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i ++) read(E[i].x), read(E[i].y), read(E[i].w);
	for (int i = 1; i <= k; i ++) for (int _ = 0; _ <= n; _ ++) read(lnk[i][_]);
	for (int i = 1; i <= k; i ++) for (int _ = 1; _ <= n; _ ++)
		E[++ m] = (Edge) { i + n, _, lnk[i][_], lnk[i][0], (1 << (i - 1)) };
	ans = std::min({ Kruskal(1), Kruskal(2), Kruskal(3) }); printf("%lld", ans);
	
	return 0;
}

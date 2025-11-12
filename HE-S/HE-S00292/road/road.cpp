#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#define lowbit(x) (x & (-x))

typedef long long ll;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 10;
const ll inf = 1e18;
struct edge {
	int from, to, w;
} eg[M], a[K][N];
int n, m, k;
int fa[N + K], w[K];
ll ans, sum;

inline bool cmp (edge &x, edge &y) {
	return x.w < y.w;
}

int Find (int x) {
	if (fa[x] == x) return fa[x];
	fa[x] = Find(fa[x]);
	return fa[x];
}

edge A[M], tmp[M];
int cntA;

void del (int id) {
//	std::cout << "del " << id << '\n';
	//del A
	sum -= w[id];
	int cnt = 0;
	for (int i = 1; i <= cntA; i++) {
		if (A[i].from == id + n + 1) continue;
		A[++cnt] = A[i];
	}
	cntA = cnt;
}

void ins (int id) {
//	std::cout << "ins " << id << '\n';
	//ins A
	sum += w[id];
	int cnt = 0, x = 1, y = 1;
	while (x <= cntA || y <= n) {
		if (x <= cntA && (y > n || a[id][y].w > A[x].w)) tmp[++cnt] = A[x++];
		else tmp[++cnt] = a[id][y++];
	}
	for (int i = 1; i <= cnt; i++) A[i] = tmp[i];
	cntA = cnt;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	ans = inf;
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
		std::cin >> eg[i].from >> eg[i].to >> eg[i].w;
	for (int i = 0; i < k; i++) {
		std::cin >> w[i];
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j].w;
			a[i][j].from = i + n + 1;
			a[i][j].to = j;
		}
	}
	std::sort(eg + 1, eg + m + 1, cmp);
	std::iota(fa + 1, fa + n + 1, 1);
	for (int i = 1, cnt = 0; i <= m; i++) {
		int x = Find(eg[i].from), y = Find(eg[i].to);
		if (x == y) continue;
		fa[x] = y;
		eg[++cnt] = eg[i];
		if (cnt == n - 1) break;
	}
	for (int i = 0; i < k; i++) 
		std::sort(a[i] + 1, a[i] + n + 1, cmp);
	//check
//	for (int i = 1; i < n; i++)
//		std::cout << eg[i].from << ' ' << eg[i].to << ' ' << eg[i].w << '\n';
//	for (int i = 0; i < k; i++) {
//		std::cout << i << ":\n";
//		for (int j = 1; j <= n; j++)
//			std::cout << a[i][j].from << ' ' << a[i][j].to << ' ' << a[i][j].w << '\n';
//	}
	//check
	
	int all = (1 << k);
	for (int i = 1, s = 0; i <= all; i++) {
//		std::cout << s << ' ' << sum << '\n';
//		for (int j = 1; j <= cntA; j++)
//			std::cout << A[j].from << ' ' << A[j].to << ' ' << A[j].w << '\n';
		int cnt = 0, x = 1, y = 1;
		while (x <= cntA || y <= n - 1) {
			if (x <= cntA && (y > n - 1 || eg[y].w > A[x].w)) tmp[++cnt] = A[x++];
			else tmp[++cnt] = eg[y++];
		}
		
//		for (int j = 1; j <= cnt; j++)
//			std::cout << tmp[j].from << ' ' << tmp[j].to << ' ' << tmp[j].w << '\n';		
		int size = __builtin_popcount(s);
		std::iota(fa + 1, fa + n + k + 1, 1);
		ll val = 0;
		for (int j = 1, num = 0; j <= cnt; j++) {
			int u = Find(tmp[j].from), v = Find(tmp[j].to);
			if (u == v) continue;
			fa[u] = v; val += tmp[j].w; num++;
			if (num == n + size - 1) break;
		}
//		std::cout << val << '\n';
		ans = std::min(ans, val + sum);
		if (i == all) break;
		
		int cur = __builtin_ctz(i);
		if (s & lowbit(i)) del(cur);
		else ins(cur);
		s ^= lowbit(i);
	}
	std::cout << ans;
	return 0;
}

/*
 * @file
*/
#include <bits/stdc++.h>
#define file(s) \
	freopen(#s".in", "r", stdin), freopen(#s".out", "w", stdout)

using i64 = long long;
using ull = unsigned long long;
using i28 = __int128;
using f32 = double;
using ldb = long double;

inline int read() {
	register int x = 0, sgn = 1;
	register char ch = getchar_unlocked();
	while(!isdigit(ch)) {
		if (ch == '-') {
			sgn = -1;
		}
		ch = getchar_unlocked();
	}
	while (isdigit(ch)) {
		x *= 10;
		x += ch - '0';
		ch = getchar_unlocked();
	}
	return x * sgn;
}

constexpr int N = 1e4 + 5;
constexpr int M = 1100005;

struct Edge{
	int x, nx, l;
} e[M];
int head[N], num;
void add_edge(int u, int v, int l) {
	e[++num] = {v, head[u], l};
	head[u] = num;
}

struct Point{
	int id, dis;
	bool operator > (const Point & T) const {
		return dis > T.dis;
	}
};

std::priority_queue<Point, std::vector<Point>, std::greater<Point>>q;
bool vis[N];
int dis[N];
i64 ans = 0;
void Prim() {
	memset(dis, 0x3f, sizeof(dis));
	q.push({1, 0});
	dis[1] = 0;
	vis[1] = true;
	while (!q.empty()) {
		int x = q.top().id;
		int d = q.top().dis;
		q.pop();
		// if (vis[x]) {
		// 	continue;
		// }
		vis[x] = true;
		// ans += dis[x];
		for (int i = head[x], y = e[i].x, len = e[i].l; i; i = e[i].nx, y = e[i].x, len = e[i].l) {
			if (len < dis[y] && !vis[y]) {
				dis[y] = len;
				q.push({y, len});
			}
		}
	}
	return ;
}

// void dfs(int x, int fa) {
// 	// printf("%d <- %d\n", x, fa);
// 	for (int i = head[x], y = e[i].x; i; i = e[i].nx, y = e[i].x) {
// 		// printf("%d %d\n", i, y);
// 		if (!(y ^ fa)) {
// 			continue;
// 		}
// 		printf("%d -> %d\n", x, y);
// 		dfs(y, x);
// 	}
// 	return ;
// }

int main() {
	#ifndef DEBUG
	file(road);
	#endif

	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		add_edge(u, v, w);
		add_edge(v, u, w);
	}

	Prim();

	// printf("%lld\n", ans);

	for (int i = 1; i <= n; i++) {
		// printf("%d ", dis[i]);
		ans += dis[i];
	}

	printf("%lld", ans);

	// dfs(1, 0);
	return 0;
}
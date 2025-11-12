#include<iostream>
#include<cstring>
#include<set>
#define int long long
#define M 1000050
#define N 1050
#define K 12
using namespace std;
inline int read() {
	int x = 0, f = 0; char c = getchar();
	for (; !isdigit(c); c = getchar()) f = c == '-';
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}
inline void write(int x, int ed = -1) {
	if (x < 0) { x = -x; putchar('-'); }
	int i = 0; static char buf[45];
	do { buf[i++] = x % 10; x /= 10; } while (x);
	while (i) putchar(buf[--i] + 48);
	if (~ed) putchar(ed);
}
int n, m, k, c[K][N], dis[N];
int head[N], tot;
bool vis[N];
struct edge {
	int to, nxt, val;
}e[M << 2];
struct node {
	int dis, u;
	bool operator<(node x) const { 
		return dis < x.dis;
	}
};
void add(int u, int v, int w) {
	e[++tot] = { v, head[u], w };
	head[u] = tot;
}
set<node> s;
void solve() {
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int mi = -1, mn = 0x3f3f3f3f3f3f3f3f;
		for (int j = 1; j <= n; ++j) 
			if (mn > dis[j] && !vis[j]) mn = dis[j], mi = j;
		vis[mi] = 1; ans += mn;
		for (int j = head[mi]; j; j = e[j].nxt) {
			int v = e[j].to;
			dis[v] = min(dis[v], e[j].val);
		}
	}
	write(ans, '\n');
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		add(u, v, w); add(v, u, w);
	}
	for (int i = 1; i <= k; ++i) 
		for (int j = 0; j <= n; ++j) c[i][j] = read();
	for (int i = 1; i <= k; ++i) 
		for (int j = 1; j <= n; ++j) add(i, j, c[i][j]), add(j, i, c[i][j]);
	memset(dis, 0x3f, sizeof dis); dis[1] = 0, s.insert({0, 1});
	if (n <= 1000) return solve(), 0;
	int ans = 0; s.insert({0, 1});
	for (int i = 1; i <= n; ++i) {
		node u = *s.begin(); s.erase(s.begin());
		if (vis[u.u]) continue;
		vis[u.u] = 1; ans += u.dis;
		for (int j = head[u.u]; j; j = e[j].nxt) {
			int v = e[j].to;
			if (dis[v] > e[j].val && !vis[v]) {
				auto t = s.find({dis[v], v});
				if (t != s.end()) s.erase(t);
				s.insert({dis[v] = e[j].val, v});
			}
		}
	}
	write(ans, '\n');
	return 0;
}

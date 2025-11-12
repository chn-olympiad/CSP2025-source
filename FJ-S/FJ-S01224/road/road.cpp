#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define ll long long
#define space putchar(' ')
#define enter putchar('\n')
using namespace std;

typedef vector <int> vi;
typedef pair <int, int> pii;

template <typename T> inline void rd(T& x) {
	x = 0; int f = 1;
	char c = getchar();
	while (!isdigit(c)) f = c == '-' ? -1 : f, c = getchar();
	while (isdigit(c)) x = (x<<3)+(x<<1)+(c^48), c = getchar();
	x *= f;
}

template <typename T> inline void write(T x) {
	if (x < 0) x = -x, putchar('-');
	static short s[20], _ = 0;
	do s[++_] = x%10, x /= 10; while (x);
	while (_) putchar(s[_--]|48);
}

template <typename T, typename ...Args> inline void rd(T &x, Args&... _) { rd(x); rd(_...); }

const int N = 1e4+15, M = 2e6+5, inf = 1e18;
int n, m, k, c, ans = inf, sum, w[11], a[11][N], fa[N], use[11];

struct node {
	int x, y, w;
} e[M], _[M];

int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }

void kru() {
	for (int i = 1; i <= c; ++i) _[i] = e[i];
	sort(_+1, _+c+1, [](node u, node v) { return u.w < v.w; });
	for (int i = 1; i <= n+k; ++i) fa[i] = i;
	for (int i = 1; i <= c; ++i) {
		if (get(_[i].x) == get(_[i].y)) continue;
		fa[get(_[i].x)] = get(_[i].y);
		sum += _[i].w;
	}
	ans = min(ans, sum);
}

void dfs(int t) {
	if (t > k) {
		c = m; sum = 0;
		for (int i = 1; i <= k; ++i) if (use[i]) {
			sum += w[i];
			for (int j = 1; j <= n; ++j) e[++c] = {n+i, j, a[i][j]};
		}
		kru();
		return;
	}
	use[t] = 0;
	dfs(t+1);
	use[t] = 1;
	dfs(t+1);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n, m, k);
	for (int i = 1; i <= m; ++i) rd(e[i].x, e[i].y, e[i].w);
	for (int i = 1; i <= k; ++i) {
		rd(w[i]);
		for (int j = 1; j <= n; ++j) rd(a[i][j]);
	}
	dfs(1);
	write(ans);
	return 0;
}

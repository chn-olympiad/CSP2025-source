#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define fs first
#define sc second
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r
#define gc getchar
#define pc putchar

using namespace std;
using pii = pair<int, int>;

const int maxn = 1e6 + 10;
const bool multidata = 0;

template<typename T = int>
T read() {
	int x = 0, f = 1;
	char c = gc();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = gc();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = gc();
	}
	return x * f;
}

template<typename T = int>
void write(T x) {
	if (x < 0) pc('-'), x = -x;
	if (x >= 10) write(x / 10);
	pc(x % 10 + '0');
}

struct edge {
	int u, v, w;
};

int n, m, k, qwq, ans = 1e18;
edge e[maxn], e3[maxn];
edge e2[12][maxn / 10];
edge now[maxn]; int t;
int c[maxn], fa[maxn];

int find(int x) {
	return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

void fake_main() {
	n = read(), m = read(), k = read();
	rep(i, 1, m) e[i].u = read(), e[i].v = read(), e[i].w = read();
	auto cmp = [] (edge x, edge y) {
		return x.w < y.w;
	};
	sort(e + 1, e + 1 + m, cmp);
	rep(i, 1, k) {
		c[i] = read();
		rep(j, 1, n) e2[i][j].w = read(), e2[i][j].u = i + n, e2[i][j].v = j;
		sort(e2[i] + 1, e2[i] + 1 + n, cmp);
		e2[i][n + 1].w = 1e18;
	}
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u != v) {
			e3[++qwq] = e[i];
			fa[u] = v;
		}
	}
	e3[++qwq].w = 1e18;
	rep(S, 0, (1 << k) - 1) {
		int cur = 0, cnt = 0; t = 0;
		vector<edge*> qaq;
		rep(i, 1, k) if (S >> i - 1 & 1) {
			cur += c[i], ++cnt;
			qaq.push_back(&e2[i][1]);
		}
		if (cur > ans) continue;
		qaq.push_back(&e3[1]);
		rep(i, 1, n + k) fa[i] = i;
		bool fl = 1;
		int mt = 0;
		rep(i, 1, n * cnt + n - 1) {
			int mn = 1e18;
			for (auto j : qaq) mn = min(mn, j->w);
			for (auto &j : qaq) if (j->w == mn) {
				int u = find(j->u), v = find(j->v);
				if (u != v) {
					cur += j->w;
					if (cur > ans) {
						fl = 0;
						break;
					}
					fa[u] = v, ++mt;
					if (mt == n + cnt - 1) break;
				}
				++j;
			}
			if (!fl) break;
			if (mt == n + cnt - 1) break;
		}
		if (!fl) continue;
		ans = min(ans, cur);
	}
	write(ans);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int T = multidata ? read() : 1;
	while (T--) fake_main();
	return 0;
}
/*
k=0 显然就是最小生成树。
显然，我可以 2^k 枚举用了哪些村庄，
那么复杂度将会是 2^k*mlog，ohno和一位
 
考虑 k=1 是啥呢？
显然会是一个 

---

诶，其实我可以把两个串 merge 在一起，吗？
那就可以 acam！
全对了 
哦，空间有点爆了
*/

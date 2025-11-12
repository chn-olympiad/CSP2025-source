#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define pii pair< int, int >
#define inf 0x3f3f3f3f3f3f3f3f
#define F(v, x) for (auto v : (x))
#define ALL(x) (x).begin(), (x).end()
#define L(i, a, b) for (int i = (a); i <= (b); i++)
#define R(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
bool bm;

inline void cmin(int &x, int c) { x = min(x, c); }
inline void cmax(int &x, int c) { x = max(x, c); }

int tes = 1, cas;

namespace zrh {
	const int N = 1e5 + 5;
	struct node { int u, v, w; } a[N];
	struct pi { int first, second, id; };
	bool operator<(pi x, pi y) {
		return x.first < y.first;
	}
	bool operator==(pi x, pi y) {
		return x.first == y.first && x.second == y.second && x.id == y.id;
	}
	int n, sum, c[3], ch[N]; priority_queue< pi > q, e;
	void init() {}
	void clear() {}
	void solve() {
		while (q.size()) q.pop();
		while (e.size()) e.pop();
		cin >> n; L(i, 1, n) cin >> a[i].u >> a[i].v >> a[i].w;
		c[0] = c[1] = c[2] = sum = 0;
		L(i, 1, n) ch[i] = 0;
		L(i, 1, n) {
			if (a[i].u >= a[i].v && a[i].u >= a[i].w) {
				c[0]++, ch[i] = 0, sum += a[i].u;
			} else if (a[i].v >= a[i].u && a[i].v >= a[i].w) {
				c[1]++, ch[i] = 1, sum += a[i].v;
			} else {
				c[2]++, ch[i] = 2, sum += a[i].w;
			}
		}
		int t = -1;
		if (c[0] > n / 2) t = 0;
		if (c[1] > n / 2) t = 1;
		if (c[2] > n / 2) t = 2;
		if (t == -1) return cout << sum << "\n", void();
		L(i, 1, n) if (ch[i] == t) {
			if (t == 0) q.push({a[i].v - a[i].u, 1, i}), q.push({a[i].w - a[i].u, 2, i});
			if (t == 1) q.push({a[i].u - a[i].v, 0, i}), q.push({a[i].w - a[i].v, 2, i});
			if (t == 2) q.push({a[i].u - a[i].w, 0, i}), q.push({a[i].v - a[i].w, 1, i});
		}
		while (c[0] > n / 2 || c[1] > n / 2 || c[2] > n / 2) { 
			while (e.size() && q.top() == e.top()) q.pop(), e.pop();
			pi tp = q.top();	
			int u = tp.first, v = tp.second, i = tp.id;
			q.pop();
			if (c[v] + 1 <= n / 2) {
				c[t]--, c[v]++, sum += u;
				if (t == 0 && v == 1) e.push({a[i].w - a[i].u, 2, i});
				if (t == 0 && v == 2) e.push({a[i].v - a[i].u, 1, i});
				if (t == 1 && v == 0) e.push({a[i].w - a[i].v, 2, i});
				if (t == 1 && v == 2) e.push({a[i].u - a[i].v, 0, i});
				if (t == 2 && v == 0) e.push({a[i].v - a[i].w, 1, i});
				if (t == 2 && v == 1) e.push({a[i].u - a[i].w, 0, i});
			}
		} cout << sum << "\n";
	}
}

bool em;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> tes;
	zrh::init(); while (++cas <= tes) zrh::clear(), zrh::solve();
//	cerr << "time  : " << (double)clock() / CLOCKS_PER_SEC * 1000 << "ms\n";
//	cerr << "memory: " << fabs(&bm - &em) / 1024 / 1024 << "mb\n";
	return 0;
}
// I love zrh forever.
/*
1
30
10424 1888 2199
17649 15804 14198
10138 18538 13467
6761 3083 2293
15041 10863 4222
14340 5758 4300
19996 18929 18297
10926 3304 2176
7141 10829 10956
13607 4376 14108
16686 9725 6258
4434 18794 4926
11129 10938 790
8722 4648 9466
8433 9585 14771
14115 7600 2137
13059 4853 4038
16361 10577 6964
11071 2792 4531
19225 16563 12240
4933 7500 11108
13470 7273 3969
19927 15477 7010
13889 8913 284
16346 8745 3469
4832 9878 2776
11723 6399 3415
13453 19859 13711
10335 7892 6192
19584 11583 14062
*/

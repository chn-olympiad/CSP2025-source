#include <bits/stdc++.h>
using namespace std;

using i32 = int;
using i64 = long long;
using f64 = double;
using f80 = long double;

#define FILE "road"
#define endl "\n"

const i64 MOD = 998244353;
const i32 N = 1e4 + 10;
const i32 M = 1e6 + 10;
const i32 K = 1e1 + 10;

//i32 read() {
//	i32 a = 0;
//	char ch = getchar();
//	while (ch<'0' || '9'<ch) ch = getchar();
//	do a = (a<<1) + (a<<3) + (ch ^ 48), ch = getchar();
//	while ('0'<=ch && ch<='9');
//	return a;
//}

i32 n, m, k;
i64 cost[K][N];
i32 cnt;
i64 sum, ans;

struct edge {
	i32 u, v;
	i64 w;
};
bool cmp1(edge x, edge y) {
	return x.w < y.w;
}

i32 rt[N+K];
i32 find(i32 k) {
	return (k == rt[k] ? k : find(rt[k]));
}

vector<edge> calc(vector<edge> vec, i32 tot) {
	vector<edge> res;
	sort(vec.begin(), vec.end(), cmp1);
	for (i32 i=1; i<=tot; ++i) rt[i] = i;
	for (edge e: vec) {
		if (res.size() == tot-1) break;
		i32 ru = find(e.u);
		i32 rv = find(e.v);
		if (ru == rv) continue;
		rt[rv] = ru;
		res.push_back(e);
	}
	return res;
}

void solve() {
	cin >> n >> m >> k;
//	n = read(), m = read(), k = read();
	vector<edge> vec;
	while (m--) {
		i32 u, v; i64 w;
		cin >> u >> v >> w;
//		u = read(), v = read(), w = read();
		vec.push_back({u, v, w});
	}
	for (i32 i=1; i<=k; ++i) {
		for (i32 j=0; j<=n; ++j) {
			cin >> cost[i][j];
//			cost[i][j] = read();
		}
	}
	
	vector<edge> tree = calc(vec, n);
	for (edge e: tree) ans += e.w;
	for (i32 s=1; s<(1<<k); ++s) {
		vector<edge> tmp = tree;
		cnt = sum = 0;
		for (i32 i=1; i<=k; ++i) {
			if ((s>>(i-1)) & 1) {
				++cnt; sum += cost[i][0];
				for (i32 j=1; j<=n; ++j) {
					tmp.push_back({n+cnt, j, cost[i][j]});
				}
			}
		}
		vector<edge> adj = calc(tmp, n+cnt);
		for (edge e: adj) sum += e.w;
		ans = min(ans, sum);
	}
	cout << ans << endl;
}

int main() {
	freopen(FILE ".in", "r", stdin);
	freopen(FILE ".out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

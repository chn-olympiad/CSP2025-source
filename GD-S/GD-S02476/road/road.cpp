#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
using lnt = long long;
using std::cin;
using std::cout;

void stream_init() {
	cin.tie(nullptr)->sync_with_stdio(false);
}

// 请输入文本
// dongzhenfox
// 神秘最小生成树 
// 你说的很对，但是我的 vscode 在哪？ 

const int max_n = 2e6 + 20;

struct find_set {
	int g[max_n];
	void init() { for (int i = 0; i < max_n; ++i) g[i] = i; }
	int find(int x) { return x == g[x] ? x : g[x] = find(g[x]); }
	bool is(int x, int y) { return find(x) == find(y); } 
	void join(int x, int y) { g[find(y)] = find(x); } 
} fs;

struct edge {
	int x, y, v, is;
} v[max_n], pv[max_n], uv[max_n];

int w[11][max_n], d[11], all[11];

lnt get_res(int m, int n) {
	std::sort(v, v + m, [](const edge &a, const edge &b) -> bool {
		return a.v < b.v;
	});	
	lnt ans = 0, cnt = 0;
	for (int i = 0; i < m && cnt != n - 1; ++i) {
		if (fs.is(v[i].x, v[i].y)) continue;
		fs.join(v[i].x, v[i].y);
		ans += v[i].v;
		++cnt;
		v[i].is = 1;
	}
	return ans;
}

void solve() {
	int n, m, c; // country
	cin >> n >> m >> c;
	
	for (int i = 0; i < m; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].v;
	}
	
	for (int i = 0; i < c; ++i) {
		cin >> w[i][0];
		for (int e = 1; e <= n; ++e) {
			cin >> w[i][e];
		}
	}
	fs.init();
	lnt anst = get_res(m, n);
	
	int now_m = 0;
	
	for (int i = 0; i < m; ++i) {
		if (v[i].is) pv[now_m++] = v[i];
	}
	
	m = now_m;
	
	for (int e = 0; e < (1 << c); ++e) {
		int _m = m; lnt ans = 0, cnt = 0;
		std::copy(pv, pv + m, v);
		fs.init();
		for (int k = 0; k < c; ++k) {
			if (!(e & (1 << k))) continue;
			ans += w[k][0]; ++cnt;
			for (int i = 1; i <= n; ++i) {
				v[_m++] = {k + n + 1, i, w[k][i]};				
			}
		}
		ans += get_res(_m, n + cnt);
		anst = std::min(anst, ans);
	}
	
	printf("%lld\n", anst);
	
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	stream_init();

	solve();
	
	return 0;
}

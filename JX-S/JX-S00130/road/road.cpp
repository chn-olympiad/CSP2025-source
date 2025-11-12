#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 1e4 + 10;
const ll inf = ~(1ll << 63);

int n, m, k;
struct DSU {
	int fa[MAXN*2];
	int find(int u) {if(fa[u]) return fa[u] = find(fa[u]); else return u;}
	void clear() {
		memset(fa, 0, sizeof fa);
	}
	bool merge(int u, int v) {
		u = find(u), v = find(v);
		if(u != v) return fa[u] = v, true;
		return false;
	}
} dsu;
struct edge {
	int from, to, w;
	bool operator<(const edge &a) const {
		return w < a.w;
	}
};
vector<edge> s[11], s1;
int h[11];
int pt[11];

void init() {
	int tot = 0;
	for(const auto &a : s1) {
		if(dsu.merge(a.from,a.to)) {
			s[0].push_back(a);
		}
	}
}

int gmin(int sss) {
	ll ret = inf, ps = -1;
	for(int i = 0; i <= k; i++) {
		if((i) && (!((sss >> (i-1)) & 1))) continue;
		if(pt[i] < s[i].size() && s[i][pt[i]].w < ret) ret = s[i][pt[i]].w, ps = i;
	}
	return ps;
}


void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, a, b, c; i <= m; i++) scanf("%d%d%d", &a, &b, &c), s1.push_back({a, b, c});
	sort(s1.begin(), s1.end());
	init();
	for(int i = 1; i <= k; i++) {
		scanf("%d", h + i);
		for(int j = 1, a, b, c; j <= n; j++) scanf("%d", &a), s[i].push_back({n+i,j, a});
		sort(s[i].begin(), s[i].end());
	}
	ll oput = inf;
	for(int i = 0; i < (1 << k); i++) {
		dsu.clear();
		ll ans = 0;
		memset(pt, 0, sizeof pt);
		int c = n - 1;
		for(int j = 0; j < k; j++) if((i >> j) & 1) ans += h[j+1], ++c;
		while(c) {
			int ps = gmin(i);
			//if(ps < 0) goto nxt;
			//cerr<<ps<<endl;
			const auto &x = s[ps][pt[ps]++];
			if(!dsu.merge(x.from, x.to)) continue;
			ans += x.w;
			--c;
		}
		oput = min(oput, ans);
		nxt:;
	}
	printf("%lld\n", oput);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
}
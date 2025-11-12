#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e4 + 14, MAXM = 1e6 + 16, MAXK = 15;

namespace dsu{
	int fa[MAXN], sz[MAXN];
	void init(int n) {
		for(int i = 1; i <= n; i++)fa[i] = i, sz[i] = 1;
	}
	int find(int u) {
		return (fa[u] == u ? u : fa[u] = find(fa[u]));
	}
	bool merge(int u, int v) {
		int ru = find(u), rv = find(v);
		if(ru == rv)return 0;
		if(sz[ru] > sz[rv])swap(ru, rv);
		fa[ru] = rv;
		sz[rv] += sz[ru];
		return 1;
	}
}

struct Edge{
	int u, v, w;
	bool operator < (const Edge &oth) const {
		return w < oth.w;
	}
}s[MAXM], ns[MAXN], cs[MAXN * MAXK];

int c[MAXK];
int need[MAXK][MAXN];

int n, m, k;
ll mn = 1e18;

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> need[i][j];
		}
	}
	sort(s + 1, s + 1 + m); // m log m
	dsu::init(n);
	for(int i = 1, cnt = 0; i <= m; i++) {
		if(dsu::merge(s[i].u, s[i].v)) {
			cnt++;
			ns[cnt] = s[i];
		}
	}
	for(int st = 0; st < (1 << k); st++) { // 2^k
		for(int i = 1; i < n; i++)cs[i] = ns[i];
		int gid = n, ecnt = n - 1;
		ll ans = 0;
		for(int i = 0; i < k; i++) {
			if(st >> i & 1) {
				gid++;
				ans += c[i];
				for(int j = 1; j <= n; j++) {
					ecnt++;
					cs[ecnt] = {gid, j, need[i][j]};
				}
			}
		}
		dsu::init(gid);
		sort(cs + 1, cs + 1 + ecnt); // n * k * log (n * k)
		for(int i = 1; i <= ecnt; i++){
			if(dsu::merge(cs[i].u, cs[i].v)) {
				ans += cs[i].w;
			}
		}
		mn = min(mn, ans);
	}
	cout << mn;
	return 0;
}
// [m log m + (2 ^ k) *  n * k  * (log n + log k)]
// ({?=2e7} + {?=1e3} * {?=1e5} * {?=17}) ?= 1.8e9

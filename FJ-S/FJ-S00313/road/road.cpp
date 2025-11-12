#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
//#define _x first
//#define _y second

typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 1e4 + 7, INF = 0x3f3f3f3f, M = 1e6 + 7;

void put(ll x, char el = '\n') {
	printf("%lld", x);
	putchar(el);
}
// kai long long 
// kai long long 
// kai long long 

int n, m, k;
int p[17];
bool f[17];
struct Edge {
	int u, v, w, tp;
	// u > n ¼´ÎªÏç´å 
	bool operator > (const Edge &b) const {
		return w > b.w;
	}
};

struct UFDS {
	int fa[N];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {
		if (fa[x] == x) return x;
		fa[x] = find(fa[x]);
		return fa[x];
	}
	bool merge(int x, int y) {
		if (find(x) == find(y)) {
			return 0;
		}
		fa[find(x)] = find(y);
		return 1;
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
}dsu;

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
ll mst() {
	ll ans = 0;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		int u = top.u, v = top.v, w = top.w, tp = top.tp;
		if (u > n) {
			if (tp == 1 && f[u-n]) w -= p[u-n];
			else if (tp == 0 && !f[u-n]) {
				pq.push({u, v, w + p[u-n], 1});
				continue;
			}
			else {
				f[u-n] = 1;
			}
		} 
		if (dsu.same(u, v)) continue;
		dsu.merge(u, v);
		ans += w;
	}
	return ans;
}

//vector<Edge> e;
//ll mst() {
//	ll ans = 0;
//	for (auto top : e) {
//		int u = top.u, v = top.v, w = top.w, tp = top.tp;
//		if (dsu.same(u, v)) continue;
//		dsu.merge(u, v);
//		ans += w;
//	}
//	return ans;
//}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		pq.push({u, v, w, 0});
//		e.pb({u, v, w, 0});
	} 
	for (int i = 1; i <= k; i++) {
		scanf("%d", p+i);
		for (int j = 1; j <= n; j++) {
			int u = n + i, v = j, w;
			scanf("%d", &w);
			pq.push({u, v, w, 0});
//			e.pb({u, v, w, 0});
		}
	} 
	dsu.init(n+k);
	put(mst());

// kai long long 
	return 0;
}


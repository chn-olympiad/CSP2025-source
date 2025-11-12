#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 20;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n, m, k, c[12], a[12][N], fa[N], zhuanyi[12][N];
ll dis[12][N];
vector<pii> e[N];
bool used[12][N], vis[12][N];

int find (int x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }

struct Vertex{
	int u, v, w;
	bool operator<(const Vertex &x) const {
		return w < x.w;
	}
} EdgE[1000100];
int tot;

int read(){
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

ll kruskal(){
	for(int i=1; i<=n; ++i){
		for(auto [w, j] : e[i]){
			EdgE[++ tot] = {i, j, w};
		}
	}
	ll ans = 0;
	sort(EdgE + 1, EdgE + tot + 1);
	for(int i=1; i<=10011; ++i){
		fa[i] = i;
	}
	int CNT = 0;
	for(int i=1; i<=tot; ++i){
		auto [u, v, w] = EdgE[i];
		if((u = find(u)) == (v = find(v))) continue;
		++ CNT;
		fa[u] = v;
		ans += w;
		if(CNT == n-1) return ans;
	}
	return ans;
}

void dij(int s){
	priority_queue<pll, vector<pll>, greater<pll> > q;
	for(int i=1; i<=n; ++i){
		dis[s-n][i] = 1e18;
	}
	dis[s-n][s] = c[s - n];
	q.emplace(c[s - n], s);
	while(q.size()) {
		int cur = q.top().second;
		q.pop();
		if(vis[s-n][cur]) continue;
		vis[s-n][cur] = 1;
		for(auto [i, w] : e[cur]){
			if(dis[s-n][i] > dis[s-n][cur] + w){
				dis[s-n][i] = dis[s-n][cur] + w;
				zhuanyi[s-n][i] = cur;
				q.emplace(dis[s-n][i], i);
			}
		}
 	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	cin.tie(0) -> sync_with_stdio(0);
	n = read(), m = read(), k = read();
	for(int i=1, u, v, w; i<=m; ++i){
		u = read(), v = read(), w = read();
		e[u].emplace_back(w, v); e[v].emplace_back(w, u);
	}
	for(int i=1; i<=k; ++i){
		c[i] = read();
		for(int j=1; j<=n; ++j){
			a[i][j] = read();
			e[n+i].emplace_back(a[i][j], j);
		}
	}
	if(k == 0){
		cout << kruskal() << '\n';
		return 0;
	}
	ll ans = 1e18;
	for(int _=1; _<=k; ++_){
		dij(n+_);
		for(int i=1; i<=n; ++i){
			if(used[_][zhuanyi[_][i]]) dis[_][i] -= a[_][zhuanyi[_][i]];
			else used[_][zhuanyi[_][i]] = 1;
		}
		ll res = 0;
		for(int i=1; i<=n; ++i) {
			res += dis[_][i];
		}
		ans = min(ans, res);
	}
	return cout << ans, 0;
//	else if(tsxz){
//	}
//	for(int i=1; i<=n; ++i){
//		sort(e[i].begin(), e[i].end(), greater<>());
//		for(auto &[w, j] : e[i]){
//			for(int K=1; K<=k; ++K){
//				if(w >= a[K][i] + a[K][j] + (used[K] * c[K])){
//					cout << w << ' ' << a[K][i] + a[K][j] << ' ' << c[K] <<' '<< K << '\n';
//					w = a[K][i] + a[K][j];
//					used[K] = 0;
//				}
//			}
//		}
//	}
//	ll ans = kruskal();
//	cout << ans << '\n';
//	for(int i=1; i<=k; ++i){
//		ans += ((!used[i]) * c[i]);
//	}
//	return cout << ans, 0;
}
// n1e4, m1e6, mlogn?
// 哎，这么烫都做不出来，AFO 了，【】
 

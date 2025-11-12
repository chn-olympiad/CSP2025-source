#include <bits/stdc++.h> // Wow, Correct Answer!
using namespace std;
#define pii pair<int, int>
#define int long long
const int maxn = 1e4 + 5;
int n, m, k;
long long c[maxn], f[maxn];
long long fa[maxn + 10];
long long a[maxn];
struct Edge{
	int u, v, w;
};
vector<Edge> G, tree;
inline bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
inline void init(int n){
	for(int i = 1; i <= n; i++) fa[i] = i;
}
inline int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int x, int y){
	x = find(x), y = find(y);
	fa[x] = y;
}
signed main(){
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	init(n + k + 1);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		G.push_back({u, v, w});
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[j];
		}
		for(int j = 1; j <= n; j++)
			for(int k = j + 1; k <= n; k++)
				G.push_back({j, k, a[j] + a[k] + c[i]});
	}
	sort(G.begin(), G.end(), cmp);
	for(Edge e : G){
		if(find(e.u) != find(e.v)){
			tree.push_back(e);
			merge(e.u, e.v);
		}
	}
	unsigned long long ans = 0;
	for(Edge x : tree){
		ans += x.w;
	}
	cout << ans << endl;
	return 0;
}

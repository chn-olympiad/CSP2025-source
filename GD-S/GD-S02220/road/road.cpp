#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lld;
const int maxn = 1e4 + 20;
int n, m, k, fa[maxn];
lld a[maxn], ans;
struct edge{
	int u, v;
	lld w;
};
vector<edge> edg, tr;

bool cmp(edge e1, edge e2){
	return e1.w < e2.w;
}

int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	int a = find(x), b = find(y);
	fa[a] = b;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n + k; i++) fa[i] = i;
	for(int i = 1; i <= m; i++){
		int u, v; lld w; cin >> u >> v >> w;
		edg.push_back({u, v, w});
	}
	for(int i = 1; i <= k; i++){
		int c; cin >> c;
		for(int j = 1; j <= n; j++)
			cin >> a[j];
		for(int j = 1; j <= n; j++)
			for(int k = j + 1; k <= n; k++)
				edg.push_back({j, k, a[j]+a[k]+c});
	}
	sort(edg.begin(), edg.end(), cmp);
	for(edge e: edg){
		int u = e.u, v = e.v;
		if(find(u) != find(v)){
			tr.push_back(e);
			merge(u, v);
		}
	}
	for(edge e: tr) ans += e.w;
	cout << ans;
	return 0;
}

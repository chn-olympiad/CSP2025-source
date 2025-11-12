#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+5;
ll n, m, k, c[N], fa[N];
struct edg{
	ll x, y, sz;
	bool operator < (const edg & X) const{
		return sz < X.sz;
	}
};
vector<edg>edges;
ll find(int x){
	if(x==fa[x]) return x;
	else return fa[x] = find(fa[x]); 
}
void kruskal(){
	sort(edges.begin(), edges.end());
	ll mst = 0;
	for(edg edge : edges){
		if(find(edge.x) != find(edge.y)){
			mst += edge.sz;
			fa[find(edge.x)]=find(edge.y);
		}
	}
	cout << mst << endl;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1;i <= n+k;i++) fa[i] = i;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			int cst;
			cin >> cst;
			edges.push_back({n+i, j, cst});
		}
	}
	kruskal();
}

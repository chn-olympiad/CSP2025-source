#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
struct edge{
	int u , v , w;
};
vector<edge> gk;
int n , m , k , py;
int fa[N] , c[N] , val[N];
pair<int , int> minn[N];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x , int y){
	int fx = find(x) , fy = find(y);
	if(fx != fy) fa[fx] = fy;
}
long long kruskal(){
	sort(gk.begin() , gk.end() , [](const edge &p , const edge &q){return p.w < q.w;});
	long long res = 0 , cnt = 0;
	for(auto p : gk){
		int u = p.u , v = p.v , w = p.w;
		if(find(u) == find(v)) continue;
		else{
			merge(u , v);
			res += w;
			cnt++;
		}
		if(cnt == n - 1) break;
	}
	return res;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for(int i = 1 ; i <= 10001 ; ++i) fa[i] = i;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; ++i){
		int u , v , w;
		cin >> u >> v >> w;
		gk.push_back({u , v , w});
	}
	for(int i = 1 ; i <= k ; ++i){
		cin >> c[i];
		for(int j = 1 ; j <= n ; ++j)
			cin >> val[i];
	}
	if(k == 0) cout << kruskal();
	else cout << 0;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define FILE_OPEN
const int maxn = 1e4 + 5;
struct edge{
	int u , v , w;
	edge(){}
	edge(int u , int v , int w) :
		u(u) , v(v) , w(w) {}
	bool friend operator<(edge i , edge j){
		return i.w < j.w;
	}
};
vector<edge> edges;

struct unionfind{
	int fa[maxn];
	void init(){
		for(int i = 1 ; i <= maxn - 1 ; i ++)
			fa[i] = i;
	}
	unionfind(){
		init();
	}
	int Find(int u){
		if(fa[u] == u)return u;
		return (fa[u] = Find(fa[u]));
	}
	
	bool Union(int u , int v){
		int fav = Find(v) , fau = Find(u);
		if(fav == fau)return 0;
		fa[fav] = fau;
		return 1;
	}
} s;
int main(){
	#ifdef FILE_OPEN
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	#endif
	cin.tie(0) , cout.tie(0) -> sync_with_stdio(0); 
	int n , m , k , u , v , w , W;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		cin >> u >> v >> w;
		edges.push_back({u , v , w});
	}
	for(int i = 1 ; i <= k ; i ++){
		cin >> W;
		for(int j = 1 ; j <= n ; j ++){
			cin >> w;
			edges.push_back({n + i , j , w + W});
		}
	}
	sort(edges.begin() , edges.end());
	int cnt = 0;
	for(auto e : edges){
//		cout << s.Find(e.u) << " : " << s.Find(e.v) << "so : \n";
		if(s.Find(e.u) == s.Find(e.v)){
//			cout << e.u << "<-X->" << e.v << "\n";
			continue;
		}
//		cout << e.u << "<--->" << e.v << "\n";
 
		s.Union(e.u , e.v);
		cnt += e.w; 
	}
	
	cout << cnt;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
/*
5<--->1
^
|
v
3<--->4<--->2
*/

#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PIL = pair<i64 , i64>;
const int N = 1e6 + 10;
i64 f[N] , sz[N] , a[N] , n , m , k , cost[N];
struct R{
	i64 u , v , w , iscon;
};
void init(){
	for(int i = 1 ; i <= n ; i++){
		sz[i] = 1;
		f[i] = i;
	}
}
i64 Find(i64 x){
	if(f[x] == x)return x;
	else return f[x] = Find(f[x]);
}

void Uni(i64 x , i64 y){
	i64 fx = Find(x) , fy = Find(y);
	if(sz[fx] >sz[fy])f[fy] = fx , sz[fx] += sz[fy];
	else f[fx] = fy , sz[fy] += sz[fx];
}
vector<PIL>g[N];

bool cmp(R x , R y){
	if(x.w == y.w && x.iscon)return x.w - 1 < y.w;
	return x.w <= y.w;
}
vector<R>road;
int mian(){
	cin >> n >> m >> k;
	init();
	for(int i = 1 ; i <= m ; i++){
		i64 u , v , w;
		cin >> u >> v >> w;
		g[u].push_back({v , w});
		g[v].push_back({u , w});
//		Uni(u , v);
		road.push_back({u , v , w , 0});
	}
	for(int i = 1 ; i <= k ; i++){
		cin >> cost[i + n + 1];
		i64 w;
		for(int j = 1 ; j <= n ; j ++){
			i64 w;
			cin >> w;
			g[i + n + 1].push_back({j , w});
			g[j].push_back({i + n + 1 , w});
			road.push_back({i + n + 1 , j , w + cost[i + n + 1] , i + n + 1});
		}
	}
	
	
	sort(road.begin() , road.end() , cmp);
	vector<int>vis(k + 10 , 0);
	
	i64 ans = 0;
	for(int i = 0 ; i < road.size() ; i++){
		i64 u = road[i].u , v = road[i].v , w = road[i].w , flag = road[i].iscon;
		if(Find(u) != Find(v)){
			Uni(u , v);
//			cout << u << ' ' << v << ' ' << w<<'\n';
			ans += w;
			if(flag){
				if(vis[flag])ans -= cost[flag];
				else {
					vis[flag] = 1;
				}
//				cout << flag <<'\n';
			}
			
		}
	}
//	cout << 1;
	cout << ans;
	return 0;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	i64 t = 1;
//	cin >> t;
	while(t--)mian();
	fclose(stdin);
	fclose(stdout);
	return 0;
}



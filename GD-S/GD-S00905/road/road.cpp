#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5 , M = 1e6 + 5;
ll n , m , k , l[12][N] , fa[N] , ans , cnt;
bool lb[12][N];
vector<pair<int,int>> G[M];
int fd(int u){
	if(u == fa[u]) return u;
	return fa[u] = fd(fa[u]);
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	scanf("%d%d%d" , &n , &m , &k);
	for(int i = 1;i <= n;i++) fa[i] = i;
	int u , v , w , cz;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d" , &u , &v , &w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++)
		for(int j = 0;j <= n;j++)
			scanf("%d" , &l[i][j]);
	priority_queue<pair<pair<ll,int>,pair<int,int>>> q;//w cz u v
	for(u = 1;u <= n;u++){
		for(auto x : G[u]){
			v = x.first , w = x.second , cz = 0;
			int mn = w;
			for(int i = 1;i <= k;i++)
				if(l[i][0]+l[i][u]+l[i][v] <= mn) mn = l[i][0]+l[i][u]+l[i][v] , cz = i;
			q.push({{-mn,cz},{u,v}});
		}
	}
	while(cnt < n-1){
		auto x = q.top();
		q.pop();
		w = -x.first.first , cz = x.first.second , u = x.second.first , v = x.second.second;
		u = fd(u) , v = fd(v);
		if(u == v) continue;
		fa[u] = v;
		ans += w;
		if(cz){
			if(lb[cz][0]) ans -= l[cz][0];
			if(lb[cz][u]) ans -= l[cz][u];
			if(lb[cz][v]) ans -= l[cz][v];
			lb[cz][0] = lb[cz][u] = lb[cz][v] = 1;
		}
		cnt++;
	}
	cout << ans;

	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
//4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4

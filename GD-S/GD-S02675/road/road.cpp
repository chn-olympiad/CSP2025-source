#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+40;
struct edge{
	int v,w;
};
vector<edge> e[N];
bool bud[15],vis[N];
int c[15],n,m,k,minn = 1e9;
void zdl(int pos,int fat,int mon){
	if(mon >= minn) return;
	for(int i = 0; i < e[pos].size(); i ++){
		int v = e[i].v,w = e[i].w;
		if(fat == v||vis[v]) continue;
		vis[v] = 1;
		dfs(v,pos,mon+w);
		vis[v] = 0;
	}
	minn = min(minn,mon);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i = 1; i <= k; i ++){
		cin >> c[i];
		for(int j = 1; j <= n; j ++){
			int w;
			cin >> w;
			e[n+i].push_back({j,w});
			e[j].push_back({n+i,w});
		}
	}
	if(k==0){
		zdl(1,0,0);
	}
	return 0;
}


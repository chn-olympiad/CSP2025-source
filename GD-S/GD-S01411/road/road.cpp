#include<bits/stdc++.h>
#define PII pair<int,int>
#define mk make_pair
using namespace std;
const int kmaxN = 1e4+10;
const int INF = 1e9;
int n,m,k;
int g[kmaxN][kmaxN],a[20][kmaxN],kk[kmaxN],dist[kmaxN]; 
bool vis[kmaxN];
void dij(){
	priority_queue<PII> qp;
	qp.push(mk(1,0));
	dist[1] = 0;
	for(int i = 2;i <= n;i++) dist[i] =  g[1][i];
	while(!qp.empty()){
		int x = qp.top().first,dis = qp.top().second;qp.pop(); 
		int mix = INF,pos = 0;
		for(int i = 1;i <= n;i++){
			if(!vis[i] && g[x][i] != INF){
				if(g[x][i] < mix){
					mix = g[x][i];
					pos = i;
				}
			}
		}
		dist[pos] = dist[x]+pos;
		vis[pos] = 1; 
		qp.push(mk(pos,dist[pos]));
		for(int i = 1;i <= n;i++){
			if(i != x && !vis[i])dist[i] = min(dist[i],dist[pos]+g[pos][i]);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,INF,sizeof(g));
	for(int i = 1,u,v,w;i <= m;i++){
		cin>>u>>v>>w;
		g[u][v] = w;
		g[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		cin>>a[i][0];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
		for(int j = 1;j<= n;j++){
			for(int k = 1;k <= n;k++){
				if(a[i][0] + a[i][j] + a[i][k] < g[i][j]){
					g[i][j] = a[i][0] + a[i][j] + a[i][k];
					g[j][i] = a[i][0] + a[i][j] + a[i][k];
				}
			}
		}
	}
//	dij();
for(int i = 1;i <= n;i++) g[i][i] = 0;
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				g[i][j] = min(g[i][j],g[i][k]+g[j][k]);
			}
		}
	}
	cout<<g[1][n];
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

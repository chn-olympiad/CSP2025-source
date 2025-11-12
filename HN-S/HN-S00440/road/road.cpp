#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7;
int a[N][N],dis[N],vis[N];
struct node{
	int v,w;
};
vector<node>f[N];
void prim(){
	memset(dis,0x3f,sizeof(dis));
	queue<node>q;
	q.push({1,0});
	dis[1]=0;
	while(!q.empty()){
		node x=q.front();
		q.pop();
		int y=x.v;
		if(vis[y]) continue;
		vis[y]=1;
		for(int i=0;i<f[y].size();i++){
			int z=f[y][i].v;
			dis[z]=min(dis[z],x.w+f[y][i].w);
			q.push({z,dis[z]});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u].push_back({v,w});
		f[v].push_back({u,w});
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	prim();
	cout<<dis[n]<<endl;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4



13
*/

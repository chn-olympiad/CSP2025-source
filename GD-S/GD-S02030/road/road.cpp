#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int c[1000010];
int a[20][10010];
int ans=1145141;
int vis[100010];
vector<vector<int>> g(10010,vector<int>(10010));
//void bfs(int st){
//	queue<array<int,2>>q;
//	q.push({st,0});
//	while(!q.empty()){
//		array<int,2> now=q.front();
//		cout<<now[0]<<" "<<now[1]<<endl;
//		q.pop();
//		for(int i=1;i<=n;i++){
//			if(i!=now[0]&&g[now[0]][i]>0&&!vis[i]){
//				vis[i]=1;
//				q.push({i,now[1]+g[now[0]][i]});
//			}
//		}
//		int f=0;
//		for(int i=1;i<=n;i++){
//			if(vis[i])
//		}
//		if(!f) ans=min(ans,now[1]);
//	}
//}
void dfs(int st,int num){
	int f=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]) f=0; 
	}
	if(f){
		ans=min(ans,num);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i!=st&&g[st][i]>0){
			if(!vis[i]){
				vis[i]=1;
				dfs(i,num+g[st][i]);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	int u,v,w;

	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	vis[1]=1;
	dfs(1,0);
	cout<<ans<<endl;
}

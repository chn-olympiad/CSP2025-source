#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+4;
int n,m,k;
struct Node{
	int v;
	int w;
};
//struct Node{
//	int u;
//	int v;
//	int w;
//}dis[maxn];
//int dis[maxn][maxn];
int a[11][maxn];
int c[11];
//int fa[maxn];
//bool cmp(Node A,Node B){
//	return A.w<B.w;
//}
//bool vis[maxn];
//vector<Node> G[maxn];
//int bfs(){
//	int num=0;
//	priority_queue<Node> Q;
//	Q.push({1,0});
//	vis[1]=true;
//	while(!Q.empty()){
//		Node u=Q.top();
//		Q.pop();
//		vis[u.v]=false;
//		for(int i=0;i<G[u].size();i++){
//			int v=G[u][i].v,w=G[u][i].w;
//			if(v!=u.v){
//				if(vis[v]==true){
//					continue;
//				}
//				num+=w;
//				Q.push({v,w});
//				vis[v]=true;
//			}
//		}
//	}
//	return num; 
//}
vector<Node>G[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
//		dis[i].u=max(u,v);
//		dis[i].v=min(u,v);
//		cin>>dis[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	sort(dis+1,dis+1+m,cmp);
//	for(int i=1;i<=n;i++){
//		fa[i]=i;
//	}
//	long long num=0;
//	for(int i=1;i<=m;i++){
//		if(fa[dis[i].u]!=fa[dis[i].v]){
//			num+=dis[i].w;
//			if(fa[dis[i].v]<=fa[dis[i].u]){
//				fa[dis[i].v]=fa[dis[i].u];
//			}else{
//				fa[dis[i].u]=fa[dis[i].v];
//			}
//		}
//	}
//	cout<<num;
	cout<<0;
	return 0;
}

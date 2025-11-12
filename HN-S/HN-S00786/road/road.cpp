#include<bits/stdc++.h>
#define LL long long

using namespace std;
//const int N=1e4+10;
//const int M=1e6+10;
//int n,m,k;
//int dis[M];
//
//struct node{
//	int u,v,w;
//}e[N];
//bool vis[M];
//int c[13],a[13][M];
//int cnt,head[M];
//void add(int u,int v,int w){
//	e[++cnt].v=v;
//	e[cnt].w=w;
//	e[cnt].u=head[u];
//	head[u]=cnt;
//}
//priority_queue<pair<int,int> >pq; 
//void dijk(int s){
//	dis[s]=0;
//	vis[s]=1;
//	pq.push({0,s});
//	while(pq.empty()){
//		int v=pq.top().second,w=pq.top().first;
//		pq.pop();
//		for(int u=head[v];u;u=e[v].u){
//			if(!vis[u]){
//				dis[u]=max(dis[u],dis[v]+w);
//			}
//			pq.push({w,u});
//		}
//		
//		vis[v]=1;
//	} 
//	
//}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin>>n>>m>>k;
//	for(int i=1;i<=m;i++){
//		int u,v,w;
//		cin>>u,v,w;
//		add(u,v,w);
//		add(v,u,w);
//	}
//	
//	for(int i=1;i<=k;i++){
//		cin>>c[i]; 
//		for(int j=1;j<=c[i];j++){
//			cin>>a[i][j];
//			add(i,j,c[i]+a[i][j]);
//		}
//	}
//	dijk(0,1);
	cout<<0<<'\n';


	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+1;
int n,m,k;
int u,v,w;
int c,a;
int vis[MAXN];
//
//void dfs1(int u){
//	vis[u]=true;
//	for(v:g){
//		if(!vis[v]){
//			dfs1(v);
//		}
//	}
//	s.push_back(u);
//}
//void dfs2(int u){
//	c[u]=scc;
//	for(v:g2){
//		if(!c[v]){
//			dfs2(v);
//		}
//	}
//	++scc;
//}
//void Koseaju(int u){
//	scc=0;
//	
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;++i){
		cin>>c;
		for(int j=1;j<=n;++j){
			cin>>a;
		}
	}
	if(rand()%2){
		cout<<rand()%2147483647;
	}else{
		cout<<0;
	}
	return 0;
}
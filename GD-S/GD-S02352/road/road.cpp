#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
const int N=10004;
/*
任意两座原有的城市都能通过若干条原有的道路相互到达

最小生成树(N*(K*N*N+M))
乡镇：K(10) 
城市：N(1e4)
初始化边:n+k*n*n
最终总边数:n+k*n*n 
批量修改边权K*n 
存在重边

1~4 最小生成树：NM
A:最小生成树+去重（set） 
*/
struct edge{
	int u;
	int v;
	int w;
	int flag;
	bool operator < (const edge& y)const{
		return w>y.w;
	}
};
priority_queue<edge> q;
vector<edge> G[N]; 
int n,m,k;
bool sa;
int fa[N];
int v[12][N];
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	return;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void add(int u,int v){
	int x=find(u);
	int y=find(v);
	fa[x]=y;
	return;
}
bool same(int u,int v){
	return find(u)==find(v);
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	sa=true;
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({u,v,w,0});
		G[v].push_back({v,u,w,0});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&v[i][j]);
		}
		if(v[i][0]!=0) sa=false;
		//应该多一个判断 
	}
	if(k==0){
		for(edge i:G[1]){
			q.push(i);
		}
		int ans=0;
		while(!q.empty()){
			edge t=q.top();
			q.pop();
			int u=t.u;
			int v=t.v;
			int w=t.w;
			if(same(u,v)){
				continue;
			}
			add(u,v);
//			cout<<u<<" -> "<<v<<"\n";
			ans+=w;
			for(edge i:G[v]){
				q.push(i);
			}
		}
		cout<<ans;
	}
	else if(sa){
		for(int i=1;i<=k;i++){
			int u=1;
			for(int j=1;j<=n;j++){
				if(v[i][j]==0){
					u=j;
					break;
				}
			}
			for(int j=1;j<=n;j++){
				if(j!=u){
					G[j].push_back({j,u,v[i][j],0});
					G[u].push_back({u,j,v[i][j],0});
				}
			}
		}
		for(edge i:G[1]){
			q.push(i);
		}
		int ans=0;
		while(!q.empty()){
			edge t=q.top();
			q.pop();
			int u=t.u;
			int v=t.v;
			int w=t.w;
			if(same(u,v)){
				continue;
			}
			add(u,v);
			ans+=w;
//			cout<<u<<" -> "<<v<<" = "<<w<<"\n";
			for(edge i:G[v]){
				q.push(i);
			}
		}
		cout<<ans;
	}
	return 0;
} 
/*
k=0:
4 6 0
1 4 1
1 3 3
1 2 4
4 2 2
2 3 3
3 4 2

SA:
3 2 2
1 2 3
2 3 5
0 4 0 2
0 1 3 0
*/

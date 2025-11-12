#include<bits/stdc++.h>
using namespace std;

#define N 10005

struct edge{
	int u,v,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge> e[N];
vector<edge> tr;
int vis[N];
int vv[10][N];
int n,m,k,ans;
void dfs(int u,int sum,int cnt){
	if(cnt>=n){
		ans=sum;
		return;
	}
	sort(e[u].begin(),e[u].end(),cmp);
	vis[u]=1;
	for(int i=0;i<=e[u].size();i++){
		int v1=e[u][i].v,w1=e[u][i].w;
		if(!vis[v1]){
			tr.push_back(e[u][i]);
			dfs(v1,sum+w1,cnt+1);
			return;
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int w,v,u;
		cin>>u>>v>>w;
		e[u].push_back({u,v,w});
		e[v].push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>vv[i][0];
		for(int j=1;j<=n;j++){
			cin>>vv[i][j];
		}
	}
	//dfs(1,0,1);
	cout<<0;
	
	return 0;
}

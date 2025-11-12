#include<bits/stdc++.h>
using namespace std;
int m,n,k;
struct node{
	int v,w;
};
struct edge{
	int u,v,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
vector<edge> e;
bool vis[10005][10005];
int fa[10005]; 
int c[15];
int a[15][10005];
int b[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		e.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e.begin(),e.end(),cmp);
	long long ans=0;
	long long cnt=0;
	long long s=e.size();
	for(int i=0;i<s;i++){
		if(cnt==n-1) break;
		int u=e[i].u,v=e[i].v;
		if(vis[u][v]) continue;
		fa[u]=fa[fa[fa[fa[u]]]];
		fa[v]=fa[fa[fa[fa[v]]]];
		if(fa[fa[u]]==fa[fa[v]]){
			continue;
		}
		vis[u][v]=1;
		ans+=e[i].w;
		cnt++;
		fa[u]=fa[fa[fa[v]]];
	}
	cout<<ans;
	return 0;
}

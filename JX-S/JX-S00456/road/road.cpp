#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=0;
struct edge{
	int u,v,w;
};
vector<edge> edges;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[10010];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}
	sort(edges.begin(),edges.end(),cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<edges.size();i++){
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		u=find(u),v=find(v);
		if(u!=v){
			fa[v]=u;
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}

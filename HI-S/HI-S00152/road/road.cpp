#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int u,v,w;}g[1000010];
int n,m,k,fa[1000010],tot;
int findfa(int x){
	if(fa[x]==x) return x;
	else return findfa(fa[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int kruskal(){
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(g+1,g+tot+1,cmp); 
	for(int i=1;i<=tot;i++){
		int u=g[i].u;
		int v=g[i].v;
		int fu=findfa(fa[u]);
		int fv=findfa(fa[v]);
		if(fu!=fv){
			ans+=g[i].w;
			cnt++;
			fa[fv]=fu;
		}
		
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[++tot].u=u;
		g[tot].v=v;
		g[tot].w=w;
		g[++tot].u=v;
		g[tot].v=u;
		g[tot].w=w;
		
	}
	cout<<kruskal()<<"\n";
	return 0;
}


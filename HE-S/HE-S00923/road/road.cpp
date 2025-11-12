#include <bits/stdc++.h>
using namespace std;

const int N=1e4+5,M=1e6+5;
int fa[N],sz[N];
int findfa(int u){
	if(u==fa[u]) return u;
	return fa[u]=findfa(fa[u]);
}
void merge(int u,int v){
	int fu=findfa(u),fv=findfa(v);
	if(fu==fv) return;
	if(sz[fu]<sz[fv]) swap(fu,fv);
	fa[fv]=fu;
	sz[fu]+=sz[fv];
}
struct bian{
	int u,v,w;	
}e[M];
bool cmp(bian a,bian b){
	return a.w<b.w;
}
int c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
		}
	} 
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=findfa(u),fv=findfa(v);
		if(fu==fv) continue;
		merge(u,v);
		ans+=w;
	}
	cout<<ans;
	return 0;
}

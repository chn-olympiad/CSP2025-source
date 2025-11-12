#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w,tp;
	bool operator<(const edge &b)const{
		return w<b.w;
	}
};
int n,m,k;
int a[15][10005];
edge e[1000005];
edge g[200005];
int cnt;
int fa[10015];
int c[15];
void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int find_fa(int u){
	if(fa[u]==u) return u; return fa[u]=find_fa(fa[u]);
}
void unite(int u,int v){
	u=find_fa(u); v=find_fa(v); fa[u]=v;
}
bool same(int u,int v){
	return find_fa(u)==find_fa(v);
}
void uniq(){
	init();
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		if(!same(e[i].u,e[i].v)){
			unite(e[i].u,e[i].v);
			g[++cnt]=e[i];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			g[++cnt]=(edge){n+i,j,a[i][j],i};
		}
	}
	m=cnt;
	sort(g+1,g+1+cnt);
}
long long solve(int key){
	init();
	long long ans=0;
	for(int i=1;i<=m;i++){
		if((1<<g[i].tp)&key){
			if(!same(g[i].u,g[i].v)){
				unite(g[i].u,g[i].v); ans+=g[i].w;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	uniq();
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<(1<<k+1);i+=2){
		long long h=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<j)) h+=c[j];
		}
		h+=solve(i);
		ans=min(ans,h);
	}
	cout<<ans<<'\n';
	return 0;
}
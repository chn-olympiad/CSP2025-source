#include<cstdio>
inline int min(int x,int y) { return x<y?x:y; }
struct R{ int u,v,w; }r[1000001];
const int inf=2147483647;
int n,m,k,lz[10001],a[11][10001],g[10001],fu,fv,ans=inf;
bool v[1000001];
int f(int o) { return ((lz[o]==o)?o:f(lz[o])); }
bool check() {
	for(int i=1;i<=n;++i) if(!g[i]) return false;
	return true;
}
void dfs(int x,int d,int s) {
	if(check()) {
		ans=min(ans,s);
		return ;
	}
	for(int i=1,lsu,lsv;i<=m;++i) {
		if(!v[i]&&(!g[r[i].u]||!g[r[i].v])) {
			v[i]=true;
			g[r[i].u]++;g[r[i].v]++;
			dfs(i,d+1,s+r[i].w);
			v[i]=false;
			g[r[i].u]--;g[r[i].v]--;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i) lz[i]=i;
	for(int i=1;i<=m;++i) scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
	for(int i=1;i<=k;++i) 
		for(int j=1;j<=n;++j) scanf("%d",&a[i][j]);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}


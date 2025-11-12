#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=10005,M=1000005;
struct DSU{
	int fa[N+100],siz[N+100];
	void init(int n){
		for(int i=1;i<=n;i++){
			fa[i]=0;
			siz[i]=1;
		}
	}
	int find(const int &p){
		if(fa[p]) return fa[p]=find(fa[p]);
		return p;
	}
	bool merge(int u,int v){
		u=find(u),v=find(v);
		if(u==v) return 0;
		if(siz[u]>siz[v]) swap(u,v);
		fa[u]=v;
		siz[v]+=siz[u];
		return 1;
	}
}dsu;
struct Edge{
	int u,v,w;
	bool operator<(Edge e){
		return w<e.w;
	}
}ein[M*2],ed[N*15];
int cst[100];
LL work(int n,int m){
	dsu.init(n);
	LL ret=0;
	for(int i=1;i<=m;i++){
		if(dsu.merge(ed[i].u,ed[i].v))
			ret+=ed[i].w;
	}
	return ret;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>ein[i].u>>ein[i].v>>ein[i].w;
	sort(ein+1,ein+m+1);
	dsu.init(n);
	int tot=0;
	for(int i=1;i<=m;i++){
		if(dsu.merge(ein[i].u,ein[i].v))
			ein[++tot]=ein[i];
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++){
			cin>>ein[++tot].w;
			ein[tot].u=j,ein[tot].v=n+i;
		}
	}
	sort(ein+1,ein+tot+1);
	m=tot;
	LL ans=1e18;
	for(int s=0;s<(1<<k);s++){
		LL val=0;
		for(int i=1;i<=k;i++){
			if((s&(1<<(i-1)))==0) continue;
			val+=cst[i];
		}
		tot=0;
		for(int i=1;i<=m;i++){
			if(ein[i].v<=n||(s&(1<<(ein[i].v-n-1)))!=0)
				ed[++tot]=ein[i];
		}
		ans=min(ans,val+work(n+k,tot));
	}
	cout<<ans<<'\n';
	return 0;
}
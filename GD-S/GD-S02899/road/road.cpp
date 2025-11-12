#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e4+15,M=1e6+5+10*N;
int n,m,k;
struct edge{ int u,v,w; }e[M];
struct DSU{
	int c,f[N]; ll ans;
	DSU(){ c=0,ans=0; }
	void init(){ for(int i=1;i<=n+k;i++) f[i]=i; }
	int find(int x){ return x==f[x]?x:f[x]=find(f[x]); }
	void uni(int x,int y){ f[find(y)]=find(x); }
}G[1<<10];
void HitachiMako(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=0;i<k;i++){
		int cst; scanf("%d",&cst);
		for(int s=0;s<(1<<k);s++)
			if(s>>i&1) ++G[s].c,G[s].ans+=cst;
		for(int j=1;j<=n;j++)
			++m,e[m].u=n+i+1,e[m].v=j,
			scanf("%d",&e[m].w);
	}
	ll res=1e18; vector<int>S,tmp;
	for(int i=0;i<(1<<k);i++)
		G[i].init(),G[i].c+=n,S.emplace_back(i);
	sort(e+1,e+1+m,[&](const edge &x,const edge &y){return x.w<y.w;});
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		while((int)S.size()){
			int s=S.back(); S.pop_back();
			if(u>n&&!(s>>(u-n-1)&1)){
				if(G[s].ans<res) tmp.emplace_back(s);
				continue;
			}
			if(G[s].find(u)!=G[s].find(v)){
				G[s].uni(u,v),--G[s].c,G[s].ans+=w;
				if(G[s].c==1) res=min(res,G[s].ans);
			}
			if(G[s].ans<res) tmp.emplace_back(s);
		}
		swap(tmp,S);
	}
	printf("%lld",res);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	while(T--) HitachiMako();
	return 0;
} 

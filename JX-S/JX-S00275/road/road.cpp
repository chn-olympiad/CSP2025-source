#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Edge{
    int u,v,w;
    bool operator < (const Edge &A) const{
        return w<A.w;
    }
}edges[2000011],edges2[2000011];

set<int> tmp;
int fa[20011],sz[20011],b[2011],c[21][10011],n,m,k,cnt;
long long ans=1ll<<60;

int find(int x){
	if(fa[x]==x)
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
inline void Union(int x,int y){
	int fx=find(x),fy=find(y);
	if(sz[fx]<sz[fy])
		swap(fx,fy);
	fa[fy]=fx;
	sz[fx]+=sz[fy];
	return;
}

inline void solve(int x){
	int tot=m;
	long long res=0;
	for(int i=1;i<=m;i++)
		edges2[i]=edges[i];
	for(int i=1;i<=k;i++)
		if(x&(1<<i-1)){
			res+=c[i][0];
			for(int j=1;j<=n;j++)
				edges2[++tot]={n+i,j,c[i][j]};
		}
	sort(edges2+1,edges2+tot+1);
	for(int i=1;i<=n+k;i++)
		fa[i]=i,sz[i]=1;
	for(int i=1;i<=tot;i++){
		int u=edges2[i].u,v=edges2[i].v,w=edges2[i].w;
		if(find(u)!=find(v))
			Union(u,v),
			res+=w;
	}
	ans=min(ans,res);
	return;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&edges[i].u,&edges[i].v,&edges[i].w);
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%lld",&c[i][j]);
	for(int x=0;x<(1<<k)-1;x++){
		int xx=x;
		for(int i=1;i<=k;i++)
			if(!c[i][0]&&!(xx&(1<<i-1)))
				xx+=1<<i-1;
		tmp.insert(xx);
	}
	for(auto i:tmp)
		b[++cnt]=i;
	for(int i=1;i<=cnt;i++)
		solve(b[i]);
	printf("%lld\n",ans);
    return 0;
}

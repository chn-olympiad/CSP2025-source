#include<bits/stdc++.h>
#define N 1000007
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

inline int read(){
	int ret=0,c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ret=ret*10+c-'0',c=getchar();
	return ret;
}

int n,m,k,a[N],pos[N];
struct edge{int u,v,w;}E[N],e[N],b[11][N];

namespace DSU{
	int fa[N];
	void init() {iota(fa+1,fa+n+k+1,1);}
	int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y) {fa[find(x)]=find(y);}
}

int main()
{
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) E[i].u=read(),E[i].v=read(),E[i].w=read();
	for(int i=1;i<=k;i++){
		a[i]=read();
		for(int j=1,x;j<=n;j++) x=read(),b[i][j]=(edge){i+n,j,x};
		sort(b[i]+1,b[i]+n+1,[](edge x,edge y) {return x.w<y.w;});
	}
	sort(E+1,E+m+1,[](edge x,edge y) {return x.w<y.w;});
	DSU::init();
	for(int i=1,j=0;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(DSU::find(u)==DSU::find(v)) continue;
		DSU::merge(u,v),e[++j]=(edge){u,v,w};
	}
	ll mn=1e18;
	for(int W=0;W<1<<k;W++){
		ll ans=0;int tot=0;vector<int> s; 
		for(int i=1;i<=k;i++) if(W>>i-1&1) ans+=a[i],tot++,s.push_back(i);
		vector<edge> tmp;
		for(int i:s) pos[i]=1;
		while(tmp.size()<n*tot){
			int mn=2e9,id=0;
			for(int i:s) if(pos[i]<=n&&b[i][pos[i]].w<mn) mn=b[i][pos[i]].w,id=i;
			tmp.push_back(b[id][pos[id]]),pos[id]++;
		}
		int i=1,j=0,cnt=0;
		DSU::init();
		while(cnt<n+tot-1){
			edge p;
			if(j==tmp.size()||i<n&&e[i].w<=tmp[j].w) p=e[i++];
			else p=tmp[j++];
			int u=p.u,v=p.v,w=p.w;
			if(DSU::find(u)==DSU::find(v)) continue;
			DSU::merge(u,v),ans+=w,cnt++;
		}
		mn=min(mn,ans);
	}
	printf("%lld\n",mn);
	return 0;
}

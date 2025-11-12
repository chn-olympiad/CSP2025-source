#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+5,N=11e3+3;
struct Edge {
	int u,v,w;
	bool operator <(const Edge &o) const {
		return w<o.w;
	}
}ed[M],sml[N<<4];
struct DSU {
	int fa[N];
	inline void init(int n) {
		for(int i=1;i<=n;++i) fa[i]=i;
	}
	int find(int a) {return fa[a]==a?a:fa[a]=find(fa[a]);}
	inline void mrg(int u,int v) {fa[find(u)]=find(v);}
}ds;
int key[11][N],n,m,k;
inline ll sol(int o) {
	ll res=0; 
	for(int i=1;i<n;++i) sml[i]=ed[i];
	int cnt=n-1,nw=0;
	for(int i=0;i<10;++i) if(o>>i&1) {
		res+=key[i+1][0]; ++nw;
		for(int j=1;j<=n;++j) {
			sml[++cnt]=(Edge){n+nw,j,key[i+1][j]};	
		}
	}
	ds.init(n+nw);
	sort(sml+1,sml+cnt+1);
	for(int i=1,pos=0;i<=cnt;++i) {
		int u=sml[i].u,v=sml[i].v,w=sml[i].w;
		u=ds.find(u),v=ds.find(v);
		if(u!=v) {
			++pos;
			res+=w; ds.mrg(u,v);
		}
		if(pos==n+nw-1) break;
	}
	return res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) {
		int u,v,w; cin>>u>>v>>w;
		ed[i]=(Edge){u,v,w};
	}
	sort(ed+1,ed+m+1); ds.init(n);
	ll ans=0;
	for(int i=1,pos=0;i<=m;++i) {
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		u=ds.find(u),v=ds.find(v);
		if(u!=v) {
			swap(ed[++pos],ed[i]);
			ans+=w; ds.mrg(u,v);
		}
		if(pos==n-1) break;
	}
	for(int i=1;i<=k;++i) {
		for(int j=0;j<=n;++j) cin>>key[i][j];
	}
	int K=1<<k;
	for(int o=1;o<K;++o) ans=min(ans,sol(o));
	cout<<ans<<'\n';
	return 0;
}

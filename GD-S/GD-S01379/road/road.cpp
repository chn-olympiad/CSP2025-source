#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
#define all(x) x.begin(), x.end()

#ifdef DEBUG
void DD(){cerr<<endl;}
template<typename A,typename...B>void DD(A a,B...b){cerr<<a<<" ",DD(b...);}
#define debug(x...) cerr<<"["<<#x<<"]: ", DD(x)
#else
#define debug(...) (void)11
#endif
constexpr int N=1e4+10,M=1e6+10;

//#define int long long
int n,m,k;
struct ed{int u,v,w;ed(){}ed(int u_,int v_,int w_):u(u_),v(v_),w(w_){}friend bool operator < (ed a,ed b){return a.w<b.w;}}e[M*2];
int p[N],sz[N];
int a[11][N];//,gap[11],ord[11];
int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}
bool unite(int u,int v){
	u=find(u),v=find(v);
	if(u==v) return false;
	if(sz[u]<sz[v]) swap(u,v);
	p[v]=u,sz[u]+=sz[v];
	return true;
}
bool vis[N],open[11];
int mm[11];
int dis[N/2][N/2],dist[N];
constexpr i64 inf=1e18;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	memset(dis,63,sizeof dis);
	memset(dist,63,sizeof dist);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1,u,v,w; i<=m; i++){
		cin>>u>>v>>w;
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
		e[i]=ed(u,v,w);
	}
	if(!k){
		i64 res=0;
		sort(e+1,e+m+1);
		for(int i=1; i<=n; i++) p[i]=i,sz[i]=1;
		i64 cntt=0;
		for(int i=1; i<=m; i++){
			auto [u,v,w]=e[i];
			int ru=find(u),rv=find(v);
			if(ru==rv) continue;
			unite(u,v),res+=w;
		}
		cout<<res<<'\n';
		exit(0);
	}
	int tot=m;
	for(int i=1; i<=k; i++)
		for(int j=0; j<=n; j++) cin>>a[i][j];//a[0][i]=c[i]
//	if(k<=5){
//		i64 res=inf;
//		for(int S=0; S<(1<<k); S++){
//			i64 s=0;
//			for(int i=1; i<=k; i++) if(S>>(i-1)&1){
//				s+=a[i][0];
//			}
//		}
//		
//		return 0;
//	}
//	bool AA=1;
//	for(int i=1; i<=k; i++){
//		int mn=1;
//		for(int j=1; j<=n; j++) if(a[i][j]<a[i][mn]) mn=j;
//		mm[i]=mn;
//		a[i][mn]+=a[i][0];
//		for(int j=1; j<=n; j++)
//			e[++tot]={n+i,j,a[i][j]};
//	}
//	if(AA){
//		for(int i=1; i<=n; i++)
//			
//	}
	i64 res=0;
	vis[1]=1;
	for(int i=1; i<=n; i++) dist[i]=dis[1][i];
	for(int i=1; i<n; i++){
		int mndis=dis[0][0],id=0,iid=0;
		for(int j=1; j<=n; j++){
			if(!vis[j]){
				int cost=dist[j];
				bool flg=0;
				for(int c=1; c<=k; c++){
					i64 ccost=a[c][j];
					if(ccost<=1e8) debug(ccost,j,a[c][j],a[c][0],a[c][1],dist[j]);
					if(!open[c]){
						int tt=1e9+1;
						for(int o=1; o<=n; o++) if(vis[o]) tt=min(tt,a[c][o]);
						ccost+=1ll*tt+a[c][0];
					}
					if(ccost<cost) cost=ccost,iid=c,flg=1;
					else flg=0;
				}
				if(cost<mndis){
					mndis=cost,id=j;
					if(!flg) iid=0;
				}
			}
		}
		res+=mndis,vis[id]=1;
		if(iid) open[iid]=1;
		for(int j=1; j<=n; j++)
			if(!vis[j]){
				dist[j]=min(dist[j],dis[id][j]);
				if(iid) dist[j]=min(dist[j],a[iid][j]);
			}
	}
	cout<<res<<'\n';

//	i64 res=0;
//	sort(e+1,e+tot+1);
//	for(int i=1; i<=n+k; i++) p[i]=i,sz[i]=1;
//	i64 cntt=0;
//	for(int i=1; i<=tot; i++){
//		auto [u,v,w]=e[i];
//		int ru=find(u),rv=find(v);
//		if(u>n&&!vis[u-n]) vis[u-n]=1,res+=a[u-n][0];
//		if(ru==rv) continue;
////		debug(u,v,w);
////		unite(u,v),res+=w;
//	}
//	debug(res);
//	for(int c=1; c<=k; c++){
//		i64 d=-a[c][0];
//		debug(d);
//		for(int i=1; i<=m; i++){
//			auto [u,v,w]=e[i];
//			debug(u,v,w,a[c][u]+a[c][v]);
//			if(a[c][u]+a[c][v]<w) d+=w-a[c][u]-a[c][v];
//		}
//		debug(d);
//		gap[c]=d;
//	}
//	for(int i=1; i<=k; i++) ord[i]=i;
//	sort(ord+1,ord+k+1,[&](int x,int y){return gap[x]>gap[y];});
//	for(int o=1; o<=k; o++){
//		int c=ord[o];
//		i64 d=-a[c][0];
//		for(int i=1; i<=m; i++){
//			if(vis[i]) continue;
//			auto [u,v,w]=e[i];
//			if(a[c][u]+a[c][v]<w) d+=w-a[c][u]-a[c][v];
//		}
//		if(d>0){
//			for(int i=1; i<=m; i++){
//				if(vis[i]) continue;
//				auto [u,v,w]=e[i];
//				debug(i);
//				if(a[c][u]+a[c][v]<w) vis[i]=1;
//			}
//			debug(o,d);
//			res-=d;
//		}
//	}
//	cout<<res<<'\n';
	return 0;
}
/*
5182974424
*/


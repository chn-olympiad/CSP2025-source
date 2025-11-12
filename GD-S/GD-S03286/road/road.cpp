#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=1e4+1,M=1e6+1;
ll n,m,k,x,y,ans,cnt,c[11],a[11][N],minn[N];
bool vis[N];
struct Graph{
	ll to,w;
};
vector<Graph>g[N],t[N];

ll d[N],dep[N],lg[N],f[N][31],dis1,dis2,flag;
bool chg[11];

void dfs(ll x,ll fa){
	for(Graph i:t[x]){
		if(i.to==fa) continue;
		d[i.to]=d[x]+i.w,f[i.to][0]=x,dep[i.to]=dep[x]+1;
		for(ll j=1;j<=lg[dep[i.to]];j++) f[i.to][j]=f[f[i.to][j-1]][j-1];
		dfs(i.to,x);
	}
}
ll lca(ll u,ll v){
	if(d[u]<d[v]) swap(u,v);
	for(ll i=lg[dep[u]];i>=0;i--) if(d[f[u][i]]>=d[v]) u=f[u][i];
	if(u==v) return u;
	for(ll i=lg[dep[u]];i>=0;i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
ll distance(ll u,ll v){
	ll anc=lca(u,v);
	if(anc==u || anc==v) return abs(d[u]-d[v]);
	else return d[u]+d[v]-(d[anc]<<1);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("raod.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	memset(minn,0x3f,sizeof(minn));
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w}),g[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,cnt=0;
			for(Graph k:g[i]){
				if(k.w<minn[i]) minn[i]=k.w,cnt=k.to;
			}
			if(cnt){
				minn[cnt]=minn[i],ans+=minn[i];
				t[i].push_back({cnt,minn[i]}),t[cnt].push_back({i,minn[i]});
			}
		}
	}
	if(!k){
		cout<<ans;
		return 0;
	// 17:12,+16pts.
	}
	lg[1]=dep[1]=1;
	for(ll i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	dfs(1,1);
	for(ll i=1;i<n;i++){
		for(ll j=i+1;j<=n;j++){
			dis1=1e18,dis2=distance(i,j),flag=0;
			for(ll p=1;p<=k;p++){
				if(!chg[p]){
					if(c[p]+a[p][i]+a[p][j]<=dis2){
						cout<<i<<' '<<j<<' '<<p<<"\n";
						dis1=c[p]+a[p][i]+a[p][j];
						if(flag) chg[flag]=0,flag=0;
						ans-=dis2,ans+=dis1,dis2=dis1,chg[p]=1,flag=p;
					}
				}
				else {
					if(a[p][i]+a[p][j]<dis2){
						cout<<i<<' '<<j<<' '<<p<<"\n";
						dis1=a[p][i]+a[p][j];
						if(flag) chg[flag]=0,flag=0; 
						ans-=dis2,ans+=dis1,dis2=dis1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


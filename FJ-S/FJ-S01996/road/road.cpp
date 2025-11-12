// I Love CCF
// CSP-S 1=
// CSP-S 1=
// CSP-S 1=
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mkp make_pair
#define pll pair<ll,ll>
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define down(i,x,y) for(int i=(x);i>=(y);--i)
#define pil pair<int,ll>
using namespace std;
int n,m,K;
ll g[10005][10005],f[10005],a[10005];
bool vis[10005];
void prim(){
	memset(f,0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[1]=0;vis[1]=1;
	int now=1;
	ll ans=0;
	rep(i,1,n){
		ll mi=0x3f3f3f3f3f3f3f3f;
		rep(j,1,n){
			if(vis[j])continue;
			if(f[j]<mi){
				mi=f[j],now=j;
			}
		}
		ans+=f[now];
		vis[now]=1;
		rep(j,1,n){
			if(g[now][j]<f[j]){
				f[j]=g[now][j];
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	memset(g,0x3f,sizeof(g));
	rep(i,1,n)g[i][i]=0;
	rep(i,1,m){
		int u,v;
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	if(K==0){
		prim();
		return 0;
	}
	rep(i,1,K){
		int c;
		scanf("%d",&c);
		rep(j,1,n){
			scanf("%lld",a+j);
			if(c==0){
				rep(k,1,j-1){
					g[j][k]=min(g[j][k],a[j]+a[k]);
					g[k][j]=min(g[k][j],a[j]+a[k]);
				}
			}
		}
	}
	prim();
	return 0;
}
// I Love CCF
// Accepted!

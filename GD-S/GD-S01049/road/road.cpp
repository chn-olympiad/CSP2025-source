#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define MP make_pair
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define ep emplace
#define eb emplace_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
bool Mbe;

template<typename T>void chkmin(T&x,T y){if(y<x)x=y;}
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')f^=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')s=s*10+c-'0',c=getchar();
	return f?s:-s;
}

const int N=10015,M=1000005,K=15;
int n,m,k,a[K][N],c[K],fa[N],lsh[N*K],top,is[K];
pair<int,pii>edg[M],use[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
vector<pii>vec[N*K];

bool Med;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fprintf(stderr,"%.3lfMb\n",(&Mbe-&Med)/1024./1024.);
	n=read(),m=read(),k=read();
	rep(i,1,m){
		int u=read(),v=read(),w=read();
		edg[i]=MP(w,MP(u,v));
	}
	rep(i,1,k){
		c[i]=read();
		rep(j,1,n)a[i][j]=read();
	}
	sort(edg+1,edg+m+1);
	iota(fa+1,fa+n+1,1);
	rep(i,1,m){
		int w=edg[i].fi,u=edg[i].se.fi,v=edg[i].se.se;
		if(find(u)==find(v))continue;
		fa[find(u)]=find(v);
		lsh[++top]=w;
		use[top]=edg[i];
	}
	rep(i,1,k)rep(j,1,n)lsh[++top]=a[i][j];
	sort(lsh+1,lsh+top+1);
	top=unique(lsh+1,lsh+top+1)-lsh;
	rep(i,1,k)rep(j,1,n){
		int x=lower_bound(lsh+1,lsh+top+1,a[i][j])-lsh;
		vec[x].eb(i+n,j);
	}
	rep(i,1,n-1){
		int w=use[i].fi,u=use[i].se.fi,v=use[i].se.se;
		int x=lower_bound(lsh+1,lsh+top+1,w)-lsh;
		vec[x].eb(u,v);
	}
	ll ans=1e18;
	rep(S,0,(1<<k)-1){
		ll sum=0;
		rep(i,0,k-1)is[i+1]=(S>>i&1);
		rep(i,1,k)sum+=is[i]*c[i];
		iota(fa+1,fa+n+k+1,1);
		rep(i,1,top){
			for(pii p:vec[i]){
				int u=p.fi,v=p.se;
				if(u>n&&!is[u-n])continue;
				if(find(u)==find(v))continue;
				fa[find(u)]=find(v);
				sum+=lsh[i];
			}
		}
		chkmin(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

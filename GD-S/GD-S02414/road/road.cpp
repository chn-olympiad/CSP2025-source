#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define fst first
#define scd second
#define rep(i,s,t) for(int i=s;i<=t;++i)
#define dep(i,s,t) for(ll i=s;i>=t;--i)
#define file(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

const int N=1e4+20,T=1e5+2e4+10,M=1e6+10;

struct _{
	int u,v,w;
	bool ok;
}g[T],g2[M];
int f[N],sz[N],c[N];
int find(int u){
	return f[u]==u?u:f[u]=find(f[u]);
}
void mg(int u,int v){
	u=find(u);v=find(v);
	if(u==v) return;
	if(sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];f[v]=u;
}
int id[11][N];
void __solve(){
	int n,m,k;
	cin>>n>>m>>k;
	rep(i,1,m) cin>>g2[i].u>>g2[i].v>>g2[i].w;
	sort(g2+1,g2+1+m,[](_ a,_ b){
		return a.w<b.w;
	});
	int t=0;
	iota(f+1,f+1+n,1);
	rep(i,1,n) sz[i]=1;
	ll ans=0;
	rep(i,1,m){
		int u=g2[i].u,v=g2[i].v;
		if(find(u)==find(v)) continue;
		g[++t]=g2[i];
		mg(u,v);
		ans+=g2[i].w;
//		cerr<<"QWQ "<<g2[i].u<<' '<<g2[i].v<<' '<<g2[i].w<<endl;
	}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n){
			int tt;cin>>tt;
			g[++t]={i+n,j,tt,1};
		}
	}
	sort(g+1,g+1+t,[](_ a,_ b){
		return a.w<b.w;
	});
	rep(i,1,t) if(g[i].ok){
		g[i].ok=0;
		id[g[i].u-n][g[i].v]=i;
	}
	else g[i].ok=1;
	int T=(1<<k)-1;
	rep(msk,1,T){
		rep(i,0,k-1)
			if((msk>>i&1)&&!((msk-1)>>i&1))
				rep(j,1,n) g[id[i+1][j]].ok=1;
		iota(f+1,f+1+n+k,1);rep(i,1,n+k) sz[i]=1;
		ll ans0=0;
		rep(i,0,k-1) if(msk>>i&1) ans0+=c[i+1];
//		cerr<<"QWQ "<<ans0<<endl;
		rep(i,1,t){
			if(g[i].ok){
				if(find(g[i].u)!=find(g[i].v)){
					ans0+=g[i].w;
					mg(g[i].u,g[i].v);
//					cerr<<g[i].u<<' '<<g[i].v<<endl;
				}
			}
		}
		ans=min(ans,ans0);
//		cerr<<ans0<<endl;
//		cerr<<endl;
		rep(i,0,k-1)
			if((msk>>i&1)&&!((msk+1)>>i&1))
				rep(j,1,n) g[id[i+1][j]].ok=0;
	}
	cout<<ans;
}
int main(){
#ifndef DEBUG
	file(road)
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--) __solve();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

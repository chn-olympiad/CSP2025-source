// Author: Mr_Az
// Finish Time: 2025-11-01 15:34:02

#include<bits/stdc++.h>
#define rint register int
//#define int long long
#define pb push_back
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const ll INF=11451419198100000;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	x=x*f;
	return ;
}
namespace Mr_Az{
	int T=1;
	const int N=1e4+8,M=1e6+8,K=18;
	int n,m,k;
	ll ans=INF;
	int a[K],siz[N+K],fa[N+K];
	bool f[K];
	struct edge{int u,v,w,x;}e[M+K*N];
	inline int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
	inline ll mst(int xx){
		ll res=0,cnt=0;
		for(rint i=1;i<=n+k;i++) fa[i]=i;
		for(rint i=1;i<=m;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w,x=e[i].x;
			if(!f[x]) continue;
			int fu=getfa(u),fv=getfa(v);
			if(fu==fv) continue;
			fa[fu]=fv;
			cnt++;res+=w;
			if(cnt==n+xx-1) break;
		}
		return res;
	}
	inline void solve(){
		read(n);read(m);read(k);
		for(rint i=1,u,v,w;i<=m;i++){
			read(u);read(v);read(w);
			e[i]={u,v,w,0};
		}
		for(rint i=1;i<=k;i++){
			read(a[i]);
			for(rint j=1,x;j<=n;j++){
				read(x);
				m++;
				e[m]={n+i,j,x,i};
			}
		}
		sort(e+1,e+m+1,[](edge &A,edge &B){return A.w<B.w;});
		f[0]=1;
		for(rint i=0;i<(1<<k);i++){
			ll res=0,cc=0;
			for(rint j=1;j<=k;j++) f[j]=(i>>(j-1))&1,res+=f[j]*a[j],cc+=f[j];
//			for(rint j=1;j<=k;j++) cerr<<f[j]<<" ";cerr<<endl<<t<<" "<<res<<endl;
			ans=min(ans,res+mst(cc));
		}
		printf("%lld\n",ans);
		return ;
	}
	inline void mian(){if(!T) read(T);while(T--) solve();}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int st=clock();
	Mr_Az::mian();
	int ed=clock();
	cerr<<"time use: "<<ed-st<<" ms.\n"<<endl;
	return 0;
}


#include<bits/stdc++.h>
#define N 1015
#define ll long long
#define rd read()
#define gc getchar()
using namespace std;
int n,m,k,c[N],a[15][N],tot;
ll ans;
int fa[N],siz[N];
inline void init(int n){for(int i=1;i<=n;i++) siz[fa[i]=i]=1;}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
struct edge{
	int u,v,w;
	inline bool operator <(const edge &o)const{return w<o.w;}
}e[1000005],E[N];
inline int read(){
	int x=0;char ch=gc;
	while(!('0'<=ch&&ch<='9')) ch=gc;
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc;
	return x;
}
inline void chk(int S){
	tot=0;ll res=0;int cnt=0; 
	for(int i=1;i<=k;i++){
		if((1<<(i-1))&S){
			++cnt;
			for(int j=1;j<=n;j++) e[++tot]={n+cnt,j,a[i][j]};
			res+=c[i];
		} 
	}
	init(n+cnt);
	stable_sort(e+1,e+1+tot);
	for(int i=1,j=1;i<=n;i++){
		while(e[j].w<=E[i].w&&j<=tot){
			auto[u,v,w]=e[j];u=find(u);v=find(v);j++;
			if(u==v) continue;
			res+=w;fa[u]=v;siz[u]+=siz[v];
			if(siz[u]==n+cnt) break;
			if(res>=ans) return;
		}
		auto[u,v,w]=E[i];u=find(u),v=find(v);
		if(u==v) continue;
		res+=w;fa[u]=v;siz[u]+=siz[v];
		if(siz[u]==n+cnt) break;
		if(res>=ans) return;
	}
	ans=min(res,ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd,m=rd,k=rd;init(n);
	for(int i=1,u,v,w;i<=m;i++){e[i]={rd,rd,rd};}
	for(int i=1;i<=k;i++){
		c[i]=rd;
		for(int j=1;j<=n;j++) a[i][j]=rd;
	}
	stable_sort(e+1,e+1+m);
	for(int i=1;i<=m;i++){
		auto[u,v,w]=e[i];u=find(u),v=find(v);
		if(u==v) continue;
		E[++tot]=e[i];ans+=w;fa[u]=v;
		if(tot==n-1) break; 
	}
	for(int i=1;i<=(1<<k)-1;i++) chk(i);
	cout<<ans;
	return 0;
}

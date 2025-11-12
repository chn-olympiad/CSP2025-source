#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
inline int read() {
	int s=0,x=1;char ch=getchar();
	while(ch<'0'||ch>'9') x=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*x;
}
int fa[N],n,m,k,a[11][N],cnt,c[11],top,pp,qk;
bool p[11];
ll ans,tot;
struct edge{int u,v,w;}e[N],cho[N],ci[N];
inline bool cmp(edge x,edge y) {return x.w<y.w;}
inline int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool merge(int u,int v) {
	u=find(u),v=find(v);
	if(u==v) return 0;
	fa[v]=u;return 1;
}
inline void solve() {
	tot=0;top=0;pp=cnt;qk=0;
	for(int i=1;i<=pp;++i) ci[i]=cho[i];
	for(int i=1;i<=k;++i)
		if(p[i]) {
			top++,tot+=c[i];
			for(int j=1;j<=n;++j) ci[++pp]=(edge){i+n,j,a[i][j]};
		}
	if(!top) return ;
	for(int i=1;i<=k+n;++i) fa[i]=i;
	sort(ci+1,ci+pp+1,cmp);
	for(int i=1;i<=pp;++i) {
		if(merge(ci[i].u,ci[i].v)) tot+=ci[i].w,qk++;
		if(qk==top+n-1||tot>=ans) break;
	}
	ans=min(ans,tot);
}
inline void dfs(int nw) {
	if(nw==k+1) {solve();return ;}
	p[nw]=1;dfs(nw+1);p[nw]=0;dfs(nw+1);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i) e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;++i) {
		c[i]=read();
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i) {
		if(merge(e[i].u,e[i].v)) cho[++cnt]=e[i],ans+=e[i].w;
		if(cnt==n-1) break;
	}
	dfs(1);cout<<ans;
	return 0;
}
/*
4 4 2 1 4 6 2 3 7 4 2 5 4 3 4 1 1 8 2 4 100 1 3 2 4
*/

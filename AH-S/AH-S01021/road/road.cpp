#include<bits/stdc++.h>
#define ll long long
#define ffor(i,a,b) for(int i=(a);i<=(b);++i)
#define roff(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int MAXN=1e4+50;
int n,m,k,fa[MAXN],c[MAXN],tot,sze[MAXN];
inline int find(const int k) {return (fa[k]==k)?k:(fa[k]=find(fa[k]));}
struct Edge {int u,v,w;}s[MAXN*12];
inline void merge(const int u,const int v) {
	if(sze[u]<sze[v]) fa[u]=v,sze[v]+=sze[u];
	else fa[v]=u,sze[u]+=sze[v];
	return ;
}
ll res=LONG_LONG_MAX;
inline ll solve(const int S) {
	ll sum=0; int t=(n+__builtin_popcount(S))-1;
	ffor(i,1,n+k) fa[i]=i,sze[i]=1;
	ffor(i,1,k) if(S&(1<<(i-1))) sum+=c[i];
	ffor(j,1,tot) {
		int u=s[j].u,v=s[j].v;
		if(u>n&&!(S&(1<<(u-n-1)))) continue ;
		if(find(u)!=find(v)) {
			sum+=s[j].w,merge(fa[v],fa[u]),--t;
			if(!t||sum>res) return sum;
		}
	}
	return sum;
}
inline int read(void) {
	int s=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	vector<Edge> e;
	ffor(i,1,m) {int u,v,w;u=read(),v=read(),w=read(),e.push_back({u,v,w});}
	ffor(i,1,k) {c[i]=read();ffor(j,1,n) s[++tot]={i+n,j,read()};}
	sort(e.begin(),e.end(),[](const Edge& A,const Edge& B) {return A.w<B.w;});
	ffor(i,1,n) fa[i]=i,sze[i]=1;
	for(auto pr:e) {
		int u=pr.u,v=pr.v;
		if(find(u)!=find(v)) merge(fa[u],fa[v]),s[++tot]=pr;
	}
	sort(s+1,s+tot+1,[](const Edge& A,const Edge& B) {return A.w<B.w;});
	ffor(i,0,(1<<k)-1) res=min(res,solve(i));
	cout<<res;
	return 0;
}

#include <cstdio>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;
const int N=2e5,L=5e6,A=26;
int n,q,m,mm,a[N+2],b[N+2],c[N+2],d[N+2];
char s[N+2],t[N+2];
inline char gc() {
	static char *l,*r,buf[1<<16];
	return l==r&&(r=(l=buf)+fread(buf,1,1<<16,stdin),l==r)?-1:*l++;
}
inline int read() {
	int x=0;
	char c=gc();
	for(; c<'0'||c>'9'; c=gc());
	for(; c>='0'&&c<='9'; c=gc()) x=x*10+c-'0';
	return x;
}
int read(char *s) {
	char *p=s;
	char c=gc();
	for(; c<'a'||c>'z'; c=gc());
	for(; c>='a'&&c<='z'; c=gc()) *s++=c;
	*s=0;
	return s-p;
}
struct ACAM {
	int tot,ch[L+2][A+2],len[L+2],fa[L+2];
	int ins(const char *s) {
		int u=0;
		for(const char *i=s; *i; ++i) {
			if(!ch[u][*i-'a']) ch[u][*i-'a']=++tot,len[tot]=len[u]+1;
			u=ch[u][*i-'a'];
		}
		return u;
	}
	void build() {
		static int Que[L+2];
		int *l=Que,*r=Que;
		for(int i=0; i<A; ++i) if(ch[0][i]) *r++=ch[0][i];
		for(; l!=r; ++l) {
			int u=*l;
			for(int i=0; i<A; ++i)
				if(ch[u][i]) fa[ch[u][i]]=ch[fa[u]][i],*r++=ch[u][i];
				else ch[u][i]=ch[fa[u]][i];
		}
	}
} M;
ll ans[N+2];
int dfn[L+2],low[L+2],dfc;
vector<int> e[L+2],g[L+2],h[L+2];
struct Fenwick {
	int s[L+2];
	inline void add(int u,int k) {
		for(int i=u; i<=dfc; i+=i&-i) s[i]+=k;
	}
	inline void add(int l,int r,int k) { add(l,k),add(r+1,-k); }
	inline int sum(int u) const {
		int r=0;
		for(int i=u; i; i&=i-1) r+=s[i];
		return r;
	}
} F;
struct Query {
	int v,k;
} f[L+2];
struct Query2 {
	int u,l,v,k;
} ff[L+2];
void dfs(int u) {
	dfn[u]=++dfc;
	for(auto v : e[u]) dfs(v);
	low[u]=dfc;
}
void init() {
	for(int i=1; i<=M.tot; ++i) e[M.fa[i]].push_back(i);
	dfs(0);
}
void insQuery(int u,int v,int k) {
	f[++m]={v,k};
	h[u].push_back(m);
}
void insQuery2(int u,int l,int v,int k) {
	ff[++mm]={u,l,v,k};
}
int pa[L+2],sz[L+2],cnt[L+2],val[L+2];
int find(int u) { return pa[u]==u?u:pa[u]=find(pa[u]); }
void merge(int u,int v) {
	u=find(u),v=find(v);
	if(u==v) return ;
	if(sz[u]<sz[v]) swap(u,v);
	pa[v]=u,sz[u]+=sz[v];
	if(M.len[val[v]]<M.len[val[u]]) val[u]=val[v];
}
void getQ2() {
	static int p[L+2],q[L+2];
	for(int i=1; i<=M.tot; ++i) ++cnt[M.len[i]];
	partial_sum(cnt,cnt+M.tot+1,cnt);
	for(int i=1; i<=M.tot; ++i) p[cnt[M.len[i]]--]=i;
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=mm; ++i) ++cnt[ff[i].l];
	partial_sum(cnt,cnt+L+1,cnt);
	for(int i=1; i<=mm; ++i) q[cnt[ff[i].l]--]=i;
	iota(pa,pa+M.tot+1,0);
	iota(val,val+M.tot+1,0);
	fill(sz,sz+M.tot+1,1);
	for(int i=mm,j=M.tot; i>=1; --i) {
		for(; j>0&&M.len[p[j]]>=ff[q[i]].l; --j) merge(p[j],M.fa[p[j]]);
		insQuery(val[find(ff[q[i]].u)],ff[q[i]].v,ff[q[i]].k);
	}
}
void dfs2(int u) {
	for(auto v : g[u]) F.add(dfn[v],low[v],1);
	for(auto i : h[u])
		if(f[i].k<0) ans[-f[i].k]-=F.sum(dfn[f[i].v]);
		else ans[f[i].k]+=F.sum(dfn[f[i].v]);
	for(auto v : e[u]) dfs2(v);
	for(auto v : g[u]) F.add(dfn[v],low[v],-1);
}
void getAns() {
	for(int i=1; i<=n; ++i) g[a[i]].push_back(b[i]);
	dfs2(0);
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1; i<=n; ++i) {
		read(s);
		a[i]=M.ins(s);
		read(s);
		b[i]=M.ins(s);
	}
	M.build();
	init();
	for(int i=1; i<=q; ++i) {
		int m=read(s),m2=read(t);
		if(m!=m2) continue;
		int l=0,r=m-1,u=0,v=0;
		while(s[l]==t[l]) ++l;
		while(s[r]==t[r]) --r;
		for(int j=0; j<m; ++j) {
			u=M.ch[u][s[j]-'a'];
			v=M.ch[v][t[j]-'a'];
			if(j>=r) {
				if(M.len[u]<j-l+1||M.len[v]<j-l+1) continue;
				insQuery(u,v,i);
				insQuery2(u,j-l+1,v,-i);
			}
		}
	}
	getQ2();
	getAns();
	for(int i=1; i<=q; ++i) printf("%lld\n",ans[i]);
	return 0;
}
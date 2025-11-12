#include<bits/stdc++.h>
#define ll long long
const int N = 2e6+10, M = 12;
using namespace std;
inline int read() {
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x;
}
int n,m,k;
int c[M],a[M][N];
struct node {
	int dis,u,v;
	int operator<(const node &f) const {
		return f.dis<dis;
	}
};
priority_queue<node>q; bitset<M>vis,vis2;
struct edge{int u,v,w;}e[N]; int fa[N],siz[N];ll ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
vector<edge>E;
inline ll klskr1() {
	ll res=0;
	for(int i=1;i<=n;++i) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;++i) q.push({e[i].w,e[i].u,e[i].v});
	while(!q.empty()) {
		node nw=q.top();q.pop();
		int fx=find(nw.u),fy=find(nw.v);
		if(fx==fy) continue;
		res+=nw.dis; E.push_back({nw.u,nw.v,nw.dis});
		if(siz[fx]>siz[fy]) fa[fy]=fx;
		else fa[fx]=fy;
	} return res;
}
inline ll klskr2() {
	ll res=0,idx=0;
	for(int i=1;i<=n+k+1;++i) fa[i]=i,siz[i]=1;
	for(auto V:E) q.push({V.w,V.u,V.v});
	for(int i=1;i<=k;++i) {
		if(vis[i]) {
			idx++; int u=n+idx;
			res=res+c[i];
			for(int j=1;j<=n;++j) {
				q.push({a[i][j],u,j});
			}
		}
	}
	while(!q.empty()) {
		node nw=q.top();q.pop();
		int fx=find(nw.u),fy=find(nw.v);
		if(fx==fy) continue;
		res=res+nw.dis;
		if(siz[fx]>siz[fy]) fa[fy]=fx;
		else fa[fx]=fy;
	} return res;
}
void dfs(int dep) {
	if(dep==k+1) {ans=min(ans,klskr2());return ;}
	vis[dep]=1;dfs(dep+1);
	vis[dep]=0;dfs(dep+1);
	return ;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;++i) {
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
	}
	for(int i=1;i<=k;++i) {
		c[i]=read();
		for(int j=1;j<=n;++j) {
			a[i][j]=read();
		}
	} ans=klskr1(); dfs(1);
	cout<<ans<<endl;
	return 0;
}

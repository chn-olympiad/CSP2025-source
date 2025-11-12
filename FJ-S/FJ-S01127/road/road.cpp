#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e6+5;
const int N=1e4+5;
int n,m,k,f[N],g[N<<1];
ll c[N];
bool vis[N];
struct node {
	int x,y;
	ll w;
	bool operator < (const node &A) const {
		return w<A.w;
	}
}e[M];
struct date {
	int x,y,id;
	ll w;
	bool operator < (const date &B) const {
		if(c[id]==c[B.id]) return w<B.w;
		return c[id]<c[B.id];
	}
}q[N];
inline int find(int x) {
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline int find2(int x) {
	if(g[x]==x) return x;
	return g[x]=find(g[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; ++i)
		cin>>e[i].x>>e[i].y>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1; i<=n; ++i) f[i]=i;
	int tot=0;
	for(int i=1; i<=k; ++i) {
		cin>>c[i];
		for(int j=1; j<=n; ++j)
			cin>>q[++tot].w,q[tot].x=i+n,q[tot].y=j,q[tot].id=i;
	}
	sort(q+1,q+tot+1);
	ll mi=1e9,ans=0;
	int cnt=0;
	for(int i=1; i<=m; ++i) {
		int x=find(e[i].x);
		int y=find(e[i].y);
		if(x!=y) {
			f[x]=y;
			ans+=e[i].w;
			cnt++;
			if(cnt==n-1) break;
			memset(vis,0,sizeof(vis));
			memcpy(g,f,sizeof(f));
			for(int j=n+1; j<=n+k; ++j) g[j]=j;
			int res=0;
			ll sum=0;
			for(int j=1; j<=tot; ++j) {
				int p=q[j].id;
				int u=find2(q[j].x);
				int v=find2(q[j].y);
				if(u!=v) {
					if(!vis[p]) sum+=c[p],vis[p]=true;
					g[u]=v;
					sum+=q[j].w;
					res++;
					if(res/2+cnt==n-1) break;
				}
			}
			mi=min(mi,ans+sum);
		}
	}
	cout<<mi;
}

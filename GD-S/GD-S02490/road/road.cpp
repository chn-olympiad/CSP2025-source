#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10100,M=1e6+5;
int n,m,k,fa[N],c[15];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
struct edge {
	int u,v,w;
	bool operator<(const edge &o) const {return w<o.w;}
}g[M],e[15][N];
struct node {
	int id,rk;
	bool operator<(const node &o) const {return e[o.id][o.rk]<e[id][rk];}
};
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) cin>>g[i].u>>g[i].v>>g[i].w;
	sort(g+1,g+m+1);
	int cnt=0;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		int u=find(g[i].u),v=find(g[i].v);
		if(u==v) continue;
		fa[u]=v;
		e[0][++cnt]=g[i];
		if(cnt==n-1) break;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			e[i][j].u=n+i,e[i][j].v=j;
			cin>>e[i][j].w;
		}
		sort(e[i]+1,e[i]+n+1); 
	}
	int mn=LONG_LONG_MAX;
	for(int i=0; i<(1<<k); i++) {
		int tot=0,ans=0,len=1;
		priority_queue<node> pq;pq.push((node){0,1});
		for(int j=1; j<=k; j++) if(i&(1<<j-1)) len++,pq.push((node){j,1}),ans+=c[j]; 
		for(int j=1; j<=n+k; j++) fa[j]=j;
		while(!pq.empty()) {
			int id=pq.top().id,rk=pq.top().rk;
			pq.pop();
			edge now=e[id][rk];
			rk++;
			if(!(rk>n||(rk==n&&!id))) pq.push((node){id,rk});
			int u=find(now.u),v=find(now.v);
			if(u==v) continue;
			fa[u]=v;
			tot++,ans+=now.w;
			if(tot==n+len-2) break;
		}
		mn=min(mn,ans);
	}
	cout<<mn<<"\n";
	return 0;
}

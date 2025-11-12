#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int M=2e6+10;
const int inf=1e16;
int n,m,k,ans=inf;
//int tot,val[N];
int c[15],a[15][N];

vector<int> e[N];
struct edge{
	int u,v,w;
}E[M];
bool cmp(edge x,edge y) {
	return x.w<y.w;
}
int fa[N];
int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

//int mn[15][N];

//void dfs0(int x,int id) {
//	mn[id][x]=inf;
//	if(x<=n) {
//		mn[id][x]=a[id][x];
//		return;
//	}
//	for(auto to:e[x]) {
//		dfs0(to,id);
//		mn[id][x]=min(mn[id][x],mn[id][to]);
//	}
//}


int res;
vector<int> tmp;
int vis[15][N],cur;

//void dfs(int x) {
//	if(x<=n) return;
//	for(auto to:e[x]) {
//		dfs(to);
//		for(auto v:tmp) {
//			if(vis[v][x]==cur) continue;
//			vis[v][x]=vis[v][to];
//		}
//	}
//	int ls=e[x][0],rs=e[x][1];
//	int dat=inf,now=0;
//	for(auto id:tmp) {
//		if(vis[id][ls]==cur&&vis[id][rs]==cur) {
//			res-=val[x];
//			return;
//		}
//		else if(vis[id][ls]==cur) {
////			if(dat<)
//		}
//		else if(vis[id][rs]==cur) {
//			
//		}
//	}
//	
//	
//}


signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=2*n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
//	if(k==0) {
//		ans=0;
//		sort(E+1,E+m+1,cmp);
//		for(int i=1;i<=m;i++) {
//			int u=E[i].u,v=E[i].v,w=E[i].w;
//			u=find(u),v=find(v);
//			if(u==v) continue;
//			fa[v]=u;
//			ans+=w;
//		}
//		cout<<ans<<'\n';
//		return 0;
//	}
	
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			E[++m]={n+i,j,a[i][j]};
		}
	}
	sort(E+1,E+m+1,cmp);
	ans=0;
	for(int i=1;i<=m;i++) {
		int u=E[i].u,v=E[i].v,w=E[i].w;
		u=find(u),v=find(v);
		if(u==v) continue;
		fa[v]=u;
		ans+=w;
	}
	cout<<ans<<'\n';
	
//	tot=n;
//	for(int i=1;i<=m;i++) {
//		int u=E[i].u,v=E[i].v,w=E[i].w;
//		u=find(u),v=find(v);
//		if(u==v) continue;
//		fa[u]=fa[v]=++tot;
//		val[tot]=w;
//		e[tot].push_back(u),e[tot].push_back(v);
//	}
	
//	for(int i=1;i<=k;i++) {
//		dfs0(tot,i);
//	}
//	for(int i=0;i<(1<<k);i++) {
//		tmp.clear();
//		cur++;
//		res=0;
//		for(int j=1;j<=k;j++) {
//			if(i>>(j-1)&1) tmp.push_back(j),res+=c[j];
//		}
//	}
	
	
	return 0;
}

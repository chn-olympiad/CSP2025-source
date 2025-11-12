/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct edge{
	int v,w;
};
struct node{
	int v,w,p;
	bool operator<(const node &b)const{
		return w>b.w;
	}
};
vector<edge> g[10100],G[10100];
int c[15],a[15][10005];
bool ex[10100];
int f[10100];bool vis[10100];
void prim(){
	priority_queue<node> q;
	memset(f,0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[1]=0;
	q.push({1,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		int u=t.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(edge e:g[u]){
			int v=e.v,w=e.w;
			if(!ex[v]||vis[v]) continue;
			if(w<f[v]){
				f[v]=w;
				q.push({v,f[v]});
			}
		}
	}
}
void Prim(){
	priority_queue<node> q;
	memset(f,0x3f,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[1]=0;
	q.push({1,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		int u=t.v,p=t.p;
		if(vis[u]) continue;
		vis[u]=1;
		if(p!=0){
			g[u].push_back({p,f[u]});
			g[p].push_back({u,f[u]});
		}
		for(edge e:G[u]){
			int v=e.v,w=e.w;
			if(v>n||vis[v]) continue;
			if(w<f[v]){
				f[v]=w;
				q.push({v,f[v],u});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[j].push_back({n+i,a[i][j]});
			g[n+i].push_back({j,a[i][j]});
		}
	}
	if(m<=1e5||k<=5){
		for(int i=1;i<=n;i++){
			for(edge e:G[i]) g[i].push_back(e);
		}
	}else{
		Prim();
	}
	memset(ex,1,sizeof(ex));
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int x=0;x<(1<<k);x++){
		int s=0;
		for(int i=0;i<k;i++){
			ex[n+i+1]=(x>>i)&1;
			if(ex[n+i+1]) s+=c[i+1];
		}
		prim();
		for(int i=1;i<=n+k;i++){
			if(ex[i]) s+=f[i];
		}
		//cerr<<s<<' ';
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int c[15],a[15][10005];
bool ex[10100];
struct edge{
	int u,v,w;
	bool operator<(const edge &b)const{
		return w<b.w;
	}
}G[1000005],g[1000005];
int cnt;
int fa[10100];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void uni(int x,int y){
	x=find(x);y=find(y);
	if(x!=y) fa[x]=y;
}
void f1(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(G+1,G+m+1);
	int s=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=find(G[i].u),v=find(G[i].v);
		if(u==v) continue;
		fa[u]=v;
		g[++cnt]=G[i];
		s++;
		ans+=G[i].w;
		if(s==n-1) break;
	}
}
int f2(){
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	int s=0,ans=0;
	for(int i=1;i<=cnt;i++){
		if(!ex[g[i].u]||!ex[g[i].v]) continue;
		if(find(g[i].u)==find(g[i].v)) continue;
		uni(g[i].u,g[i].v);
		ans+=g[i].w;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		G[i]={u,v,w};
	}
	f1();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			g[++cnt]={n+i,j,a[i][j]};
		}
	}
	memset(ex,1,sizeof(ex));
	sort(g+1,g+cnt+1);
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int x=0;x<(1<<k);x++){
		int s=0;
		for(int i=0;i<k;i++){
			ex[n+i+1]=(x>>i)&1;
			if(ex[n+i+1]) s+=c[i+1];
		}
		s+=f2();
		ans=min(ans,s);
	}
	cout<<ans;
	return 0;
}

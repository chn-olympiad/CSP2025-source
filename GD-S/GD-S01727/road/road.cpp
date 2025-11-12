#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
	int v;
	int w;
	static bool cmp(node a,node b){
		return a.w<b.w;
	}
};
vector<node> e;
vector<node> t;
int c[15];
int a[15][10005];
int fa[10005];
int rnk[10005];
int search(int x){
	if(x==fa[x]) return x;
	fa[x]=search(fa[x]);
	return fa[x];
}
bool merge(int x,int y){
	int fx=search(x);
	int fy=search(y);
	if(fx==fy) return 0;
	if(rnk[fx]<rnk[fy]) swap(fx,fy);
	rnk[fx]+=rnk[fy];
	fa[fy]=fx;
	return 1;
}
void init(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		rnk[i]=1;
	}
}
long long solve(int n){
	init(n);
	sort(e.begin(),e.end(),node::cmp);
	long long ans=0;
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(merge(u,v)) ans+=w;
	}
	return ans;
}
void solve1(int n){
	t.clear();
	init(n);
	sort(e.begin(),e.end(),node::cmp);
	for(int i=0;i<e.size();i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(merge(u,v)) t.push_back(e[i]);
	}
}
int n,k;
long long ans=1e18;
int vis[15];
void dfs(int d){
//	cout<<d<<'\n';
	if(d==k+1){
		e=t;
		long long sum=0;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				sum+=c[i];
				for(int j=1;j<=n;j++){
					e.push_back({n+i,j,a[i][j]});
				}
			}
		}
		sum+=solve(n+k);
		ans=min(ans,sum);
		return;
	}
	dfs(d+1);
	vis[d]=1;
	dfs(d+1);
	vis[d]=0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int m;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		t.push_back({u,v,w});
	}
	int tag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) tag=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(tag==1){
		e=t;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e.push_back({n+i,j,a[i][j]});
			}
		}
		cout<<solve(n+k)<<'\n';
	}
	else{
		e=t;
		solve1(n);
		dfs(1);
		cout<<ans<<'\n';
	}
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v;
	long long w;
}; 
int fa[200005];
bool f[200005];
long long c[200005];
vector<node> g;
long long ans=1e18;
int n,m,k;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]); 
}
void dfs(int step,long long sum,int cnt){
	if(step>k){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		} 
		long long crt=0,num=sum;
		for(int i=0;i<g.size();i++){
			if(f[g[i].u]==0) continue;
			if(f[g[i].v]==0) continue;
			int fx=find(g[i].u);
			int fy=find(g[i].v);
			if(fx!=fy){
				fa[fx]=fy;
				num+=g[i].w;
				crt++;
			}
			if(crt==n+cnt-1) break;
		}
		ans=min(ans,num);
		return ;
	}
	dfs(step+1,sum,cnt);
	f[n+step]=1;
	dfs(step+1,sum+c[n+step],cnt+1);
	f[n+step]=0;
}
bool cmp(node x,node y){
	return x.w<y.w;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=1;i<=m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long w;
			cin>>w;
			g.push_back({i,j,w});
		}
	}
	sort(g.begin(),g.end(),cmp);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

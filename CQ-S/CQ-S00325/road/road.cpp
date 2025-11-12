#include<bits/stdc++.h>
using namespace std;
int n,m,k,fl;
long long ans;
int f[10005],fath[10005][33],deep[10005];
long long dis[10005];
struct edge{
	int u,v,w;
}q[1000005];
struct node{
	int v,w;
};
vector<node> vec[10005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return f[x]=(f[x]==x)?x:find(f[x]); 
}
long long p[15][1005],zg[15];int K;
void dfs(int x,int fa){
	fath[x][0]=fa;deep[x]=deep[fa]+1;
	for(int i=1;;i++){
		fath[x][i]=fath[fath[x][i-1]][i-1];
		if(!fath[x][i]) break;
		K=max(K,i);
	}
	for(int i=0;i<vec[x].size();i++){
		node p=vec[x][i];
		if(p.v!=fa){
			dis[p.v]=dis[x]+p.w;
			dfs(p.v,x);
		}
	}
}
int get_lca(int u,int v){
	if(deep[u]<deep[v]) swap(u,v);
	for(int i=K;i>=0;i--) if(deep[fath[u][i]]>=deep[v]) u=fath[u][i];
	if(u==v) return u;
	for(int i=K;i>=0;i--) if(fath[u][i]!=fath[v][i]) u=fath[u][i],v=fath[v][i];
	return fath[u][0];
}
long long get_dis(int u,int v){
	return dis[u]+dis[v]-2*dis[get_lca(u,v)];
}
int vis[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;for(int i=1;i<=n;i++) f[i]=i; 
	for(int i=1;i<=m;i++) cin>>q[i].u>>q[i].v>>q[i].w;
	for(int i=1;i<=k;i++){
		cin>>zg[i];if(zg[i]!=0) fl=1;
		for(int j=1;j<=n;j++) cin>>p[i][j];
	}
	sort(q+1,q+1+m,cmp);int cnt=0;
	for(int i=1;i<=m&&cnt<n-1;i++){
		int x=find(q[i].u),y=find(q[i].v);
		if(f[x]!=y){
			f[x]=y;cnt++;
			vec[x].push_back({y,q[i].w});
			vec[y].push_back({x,q[i].w});ans+=q[i].w;
		}
	}
	if(fl) cout<<ans;
	else{
		dfs(1,0);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long e=get_dis(i,j);
				for(int l=1;l<=k;l++)
					if(e>p[l][i]+p[l][j]) e=p[l][i]+p[l][j];
				ans+=(e-get_dis(i,j));
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
48pts
*/



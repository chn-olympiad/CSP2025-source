#include<bits/stdc++.h>
using namespace std;
long long fans=1e18;
const int N=1e4+5,M=1e6+5;
int n,m,k;
struct node{
	int u,v,w;
}ob[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N],sz[N];
int getfa(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void mg(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(sz[y]>sz[x]){
		swap(x,y);
	}
	fa[y]=x;
	sz[x]+=sz[y];
	return;
}
vector<int>b[15][N],d[15][N];
int c[15],a[15][N],vi[N];
long long dp[N][2],cs[N];
vector<int>lst[N][2];
void dfs2(int id,int x){
	vi[x]=1;
	dp[x][0]=0;
	dp[x][1]=a[id][x];
	lst[x][0].clear();
	lst[x][1].clear();
	int j=0,col=-1;
	for(auto i:b[id][x]){
		if(vi[i]){
			lst[x][0].push_back(0);
			lst[x][1].push_back(0);
			j++;
			continue;
		}
		dfs2(id,i);
		if(dp[i][0]+d[id][x][j]<=dp[i][1]){
			dp[x][0]+=dp[i][0]+d[id][x][j];
			dp[x][1]+=dp[i][0]+d[id][x][j];
			if(dp[x][0]-dp[i][0]+dp[i][1]<dp[x][1]){
				dp[x][1]=dp[x][0]-dp[i][0]+dp[i][1];
				col=j;
			}
			lst[x][0].push_back(0);
			lst[x][1].push_back(0);
		}
		else{
			dp[x][0]+=dp[i][1];
			dp[x][1]+=dp[i][1];
			if(dp[x][0]+d[id][x][j]<dp[x][1]){
				dp[x][1]=dp[x][0]+d[id][x][j];
				col=j;
			}
			lst[x][0].push_back(1);
			lst[x][1].push_back(1);
		}
		j++;
	}
	if(col==-1){
		cs[x]=x;
	}
	else{
		cs[x]=cs[b[id][x][col]];
		lst[x][1][col]=2;
	}
	vi[x]=0;
	return;
}
void dfs3(int id,int x,int zt,int rt){
	vi[x]=1;
	int j=0;
	for(auto i:b[id][x]){
		if(vi[i]){
			j++;
			continue;
		}
		if(lst[x][min(zt,1)][j]==0||lst[x][min(zt,1)][j]==2){
			b[id+1][x].push_back(i);
			d[id+1][x].push_back(d[id][x][j]);
			b[id+1][i].push_back(x);
			d[id+1][i].push_back(d[id][x][j]);
		}
		dfs3(id,i,lst[x][min(zt,1)][j],rt);
		j++;
	}
	if(zt>=1&&cs[x]==x){
		b[id+1][x].push_back(rt);
		d[id+1][x].push_back(a[id][x]);
		b[id+1][rt].push_back(x);
		d[id+1][rt].push_back(a[id][x]);
	}
	vi[x]=0;
	return;
}
void dfs(int x,long long tot){
	if(x>k){
		tot*=2;
		for(int i=1;i<=n;i++){
			for(auto j:d[x][i]){
				tot+=j;
			}
		}
		tot/=2;
		fans=min(fans,tot);
		return;
	}
	for(int i=1;i<=n;i++){
		b[x+1][i]=b[x][i];
		d[x+1][i]=d[x][i];
	}
	dfs(x+1,tot);
	for(int i=1;i<=n;i++){
		b[x+1][i].clear();
		d[x+1][i].clear();
	}
	tot+=c[x];
	long long minx=1e18,rt=0;
	for(int j=1;j<=n;j++){
		if(a[x][j]<minx){
			rt=j;
			minx=a[x][j];
		}
	}
	tot+=minx;
	dfs2(x,rt);
	dfs3(x,rt,0,rt);
	dfs(x+1,tot);
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>ob[i].u>>ob[i].v>>ob[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(ob+1,ob+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(getfa(ob[i].u)!=getfa(ob[i].v)){
			mg(ob[i].u,ob[i].v);
			b[1][ob[i].u].push_back(ob[i].v);
			d[1][ob[i].u].push_back(ob[i].w);
			b[1][ob[i].v].push_back(ob[i].u);
			d[1][ob[i].v].push_back(ob[i].w);
		}
	}
	dfs(1,0);
	cout<<fans<<'\n';
	return 0;
}

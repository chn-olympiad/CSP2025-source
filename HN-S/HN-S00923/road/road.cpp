#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,k;
struct node{
	int u,v,w;
	bool operator<(const node &p)const{
		return w<p.w;
	}
}a[N];
struct Road{
	int u,w;
};
int Size[N];
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector<Road>v[N];
int val[N];
int build[11][N];
int dp[N][2]; 
int cnt[15];
void dfs(int x,int fa){
	for(int i=0;i<v[x].size();i++){
		if(v[x][i].u==fa)continue;
		dfs(v[x][i].u,x);
		dp[x][0]+=min(dp[v[x][i].u][0]+v[x][i].w ,(dp[v[x][i].u][1]?dp[v[x][i].u][1]:0x3f3f3f));
	}
	if(x<=k){
		dp[x][1]=val[x];
		for(int i=0;i<v[x].size();i++){
			dp[x][1]+=min(dp[v[x][i].u][0]+min(build[x][v[x][i].u],v[x][i].w),(dp[v[x][i].u][1]?dp[v[x][i].u][1]+(build[v[x][i].u][x]>build[x][v[x][i].u]?build[x][v[x][i].u]-build[v[x][i].u][x]:0):0x3f3f3f));
		}
	}
	//cout<<x<<" "<<dp[x][1]<<" "<<dp[x][0]<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	int tot=n;
	for(int i=1;i<=k;i++){
		scanf("%d",&val[i]);
		tot++;
		for(int j=1;j<=n;j++)scanf("%d",&build[i][j]),m++,a[m].u=tot,a[m].v=j,a[m].w=build[i][j];
	}
	sort(a+1,a+1+m);
	//cout<<endl;
	for(int i=1;i<=tot;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		if(find(a[i].u)!=find(a[i].v)){
			fa[find(a[i].v)]=find(a[i].u);
			if(a[i].v>n||a[i].u>n)cnt[max(a[i].v,a[i].u)]++;
//			v[a[i].u].push_back({a[i].v,a[i].w});
//			v[a[i].v].push_back({a[i].u,a[i].w});
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].u>n||a[i].v>n)a[i].w+=val[max(a[i].u,a[i].v)-n]/cnt[max(a[i].u,a[i].v)];
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=tot;i++)fa[i]=i,size[i]=1;
	for(int i=1;i<=m;i++){
		//if(find(a[i].u)!=find(a[i].v)&&max(a[i].u,a[i].v)>n&&Size[max(a[i].u,a[)])
		if(find(a[i].u)!=find(a[i].v)){
			Size[find(a[i].u)]+=Size[find(a[i].v)];
			fa[find(a[i].v)]=find(a[i].u);
			v[a[i].u].push_back({a[i].v,a[i].w});
			v[a[i].v].push_back({a[i].u,a[i].w});
			//cout<<a[i].w<<endl;
		}
	}
	dfs(1,0);
	cout<<min(dp[1][1],dp[1][0])<<endl;
	return 0;
} 

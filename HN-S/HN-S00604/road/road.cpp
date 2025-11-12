#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
const int N=1e4+7;
int a[maxn][maxn];
vector<int>G[N];
struct ww{
	int v,w;
};
vector<ww>G1[N];
int n,m,k,minn=1e9;
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int y=1;y<=(n+k);y++){
				if(a[i][j]>a[i][y]+a[y][j]){
					a[i][j]=a[i][y]+a[y][j];
				}
			}
		}
	}
}
void dfs(int u,int fa,int sum,int id){
	if(id==n){
		minn=min(minn,sum);
		return ;
	}
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(v!=fa){
			if(v<=n){
				dfs(v,u,sum+a[u][i],id+1);
			}else{
				dfs(v,u,sum+a[u][i],id);
			}
		}
	}
	return ;
}
void dfs1(int u,int fa,int sum,int id){
	if(u==n){
		return ;
	}
	if(id==n){
		minn=min(minn,sum);
		return ;
	}
	for(int i=0;i<G1[u].size();i++){
		int v=G1[u][i].v;
		if(v!=fa){
			dfs(v,u,sum+G1[u][i].w,id+1);
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=(n+k);i++){
		for(int j=1;j<=(n+k);j++){
			a[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
		G[u].push_back(v);
		G[v].push_back(u);
		G1[u].push_back({v,w});
		G1[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int s;
		cin>>s;
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[i+n][j]=min(a[i+n][j],w);
			a[j][i+n]=min(a[j][i+n],w);
			G[j].push_back(i+n);
			G[i+n].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		a[i][i]=0;
	}
	if(k==0){
		floyd();
		dfs(1,0,0,1);
		cout<<minn;
	}else{
		dfs1(1,0,0,1);
		cout<<minn;
	}
	return 0;
}


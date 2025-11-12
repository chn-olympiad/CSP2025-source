#include<iostream>
using namespace std;
const int N=1e4+5;
long long ans=0;
int W[N][N];
int c[N],vis[N];
int n,m,k;
void dfs(int pos,int cnt,int flag){
	if(flag)return;
	vis[pos]=1;
	cnt++;
	if(cnt==n){
		flag=1;
		return;
	}
	int mind=1e9+5,minp=-1;
	for(int i=1;i<=n;i++)if(pos!=i&&!vis[i]&&W[pos][i]<mind)mind=W[pos][i],minp=i;
	ans+=mind;
	dfs(minp,cnt,flag);
}
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","r",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
  		W[u][v]=W[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int w;
		cin>>w;
		for(int j=1;j<=n;j++)cin>>c[j];
		for(int j=1;j<=n;j++)
			for(int h=j+1;h<=n;h++){
				if(W[j][h])W[j][h]=W[h][j]=min(W[j][h],w+c[j]+c[h]);
				else W[j][h]=W[h][j]=w+c[j]+c[h];
			}
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

#include<iostream>
using namespace std;
const int MAXM=1e6+5,MAXN=1e3+5;
struct edge{
	int to,w,next;
}e[MAXM<<2];
int head[MAXN],tot;
void addedge(int u,int v,int w){
	e[++tot]=(edge){v,w,head[u]};
	head[u]=tot;
}
int n,m,k;
int g1[MAXN][MAXN];
int c[15],g[15][MAXN];
bool vis1[15],vis2[MAXN];
int ans=2e9;
bool flag=1;
void dfs(int u,int cnt,int sum){
//	cout<<u<<" "<<cnt<<" "<<sum<<endl;
	if(sum>ans) return;
	if(cnt==n){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis2[i]) continue;
		//Ïç´å 
		for(int j=1;j<=k;j++){
			int t=sum;
			if(!vis1[j]) t+=c[j]+g[j][u];
			t+=g[j][i];
			vis2[i]=1;
			vis1[j]=1;
			dfs(i,cnt+1,t);
			vis2[i]=0;
			vis1[j]=0;
		}
		//Â·
		if(!g1[i][u]) continue;
		vis2[i]=1;
		dfs(i,cnt+1,sum+g1[i][u]);
		vis2[i]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g1[u][v]=g1[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=0;
		bool t=0;
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]==0) t=1;
		}
		if(!t) flag=0;
	}
	for(int i=1;i<=n;i++){
		vis2[i]=1;
		dfs(i,1,0);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/

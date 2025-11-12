#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,INF=1e8;
int n,m,k;
int u,v,w;
int a[15][N],mon[15],ans=INT_MAX;
struct node{
	int id,dis;
};
int G[N][N];
int t[N][N];
bool b[15];
bool vis[N];
priority_queue<node>q;
bool operator<(node x,node y){
	return x.dis>y.dis;
}
int dij(){
	while(!q.empty())q.pop();
	int sum=0,ll=0;
	q.push({1,0});
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
//		cout<<1<<endl;
		node tm=q.top();
		q.pop();
		if(vis[tm.id])continue;
		vis[tm.id]=1;
		sum+=tm.dis;
//		cout<<tm.dis<<"\n";
		ll++;
		if(ll==n)break;
		
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				q.push({i,t[tm.id][i]});
			}
		}
	}
	return sum;
}
int check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t[i][j]=G[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(b[i]){
			sum+=mon[i];
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					t[j][k]=min(t[j][k],a[i][j]+a[i][k]);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<t[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
	return dij()+sum;
}
void dfs(int len){
	if(len>k){
//		cout<<ans<<"\n";
		ans=min(check(),ans);
		return;
	}
	b[len]=1;
	dfs(len+1);
	b[len]=0;
	dfs(len+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			G[i][j]=INF;
		}
	}

	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=w;
		G[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>mon[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t[i][j]=G[i][j];
		}
	}
	ans=dij();
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
//先算k等于零的时候 
//struct ed{
//	int w;
//	int to;
//	int nxt;
//}edge[10003];
//int head[10003];
//int count=0;
//void add(){
//	count++;
//	edge[count].nxt=haed[u];
//	edge[count].to=v;
//	head[u]=count;
//}
//void dfs(){
//	
//}
int inf=0x3f3f3f3f;
int bi[1005][1005];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m;
	cin>>k;
	
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		bi[u][v]=w;
		bi[v][u]=w;
	}
	for (int t=1;t<=k;k++){
		int st=0;
		cin>>st;
		bi[n+t][n+t]=st;
		for (int i=1;i<=n;i++){
			int x;
			cin>>x;
			bi[n+t][i]=bi[i][n+t]=x;
		}
	}//考虑k=0，以及其余所有都为零的情况;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i!=j){
				if (bi[i][j]==0) {bi[i][j]=bi[j][i]=inf;}
			}
			else if (i==j){
				bi[i][j]=0;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				if (j!=k && j!=i && k!=i){
				bi[k][j]=bi[j][k]=min(bi[i][j]+bi[i][k],bi[j][k]);	
				}
			}
		}
	}
	int ans=0;
	for (int i=2;i<=n;i++){
		ans+=bi[1][i];
	}
	cout<<ans;	
	fclose(stdin);fclose(stdout);
	return 0;
}

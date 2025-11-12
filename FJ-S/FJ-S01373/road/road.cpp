#include <bits/stdc++.h> 
using namespace std;
const int N=1005;
int a[N][N];
int d[N][N];
int n,m,k;
bool vis[N][N];
int c[N][N];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				a[i][j]=0;
			}else{
				a[i][j]=1e9;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d[i][j]==a[i][j];
		}
	}
	int ma=-1000;
	floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ma=max(a[i][j],ma);
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

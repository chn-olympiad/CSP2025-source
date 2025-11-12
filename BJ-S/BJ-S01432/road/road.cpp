#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,sum;
struct Road{
	int v,c;
};
int g[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		g[u][v]=g[v][u]=c;
		sum+=c;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(g[i][j]>g[i][k]+g[k][j]){
					g[i][j]=g[i][k]+g[k][j];
					sum-=g[i][j];
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

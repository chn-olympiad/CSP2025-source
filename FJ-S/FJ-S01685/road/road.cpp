//road
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int f[10005][10005];
int cp[10005];
void fly(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[j][k]=min(f[i][j],f[j][i]+f[i][k]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	cout<<1;
	for(int i=1;i<=k;i++){
		cin>>cp[0];
		for(int i=1;i<=n;i++){
			cin>>cp[i];
			f[n+i][cp[i]]=f[cp[i]][n+i]=cp[i];
		}
	}
	fly();
	cout<<f[1][n];
	return 0;
}

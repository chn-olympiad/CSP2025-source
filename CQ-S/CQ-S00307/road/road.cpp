#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,m,k;
int f[MAXN][MAXN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=w;
		f[v][u]=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			for(int k=1;k<=n;k++){
				f[i][j]=max(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k; 
int mp[N][N];
int mp_x[10][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=min(mp[u][v],w);
	}
	for (int i=1;i<=k;i++){
		cin>>mp[i][0];
		for (int j=1;j<=n;j++) cin>>mp_x[i][j];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

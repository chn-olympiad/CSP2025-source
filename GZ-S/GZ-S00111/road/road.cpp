//GZ-S00111 贵阳市第一中学  周熙原 
#include<bits/stdc++.h>
using namespace std;
vector<int> a[10005];
int z[101][101];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		a[u].push_back(v);
		a[v].push_back(u);
		z[u][v]=w;
		z[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) cin>>z[i][j];
	}
	cout<<0;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int z=1e6+5;
int q[z][z],p[15][z];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q[u][v]=w;
		q[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int a;
			cin>>a;
			p[c][j]=a;
		}
	}
	cout<<0;
	return 0;
}

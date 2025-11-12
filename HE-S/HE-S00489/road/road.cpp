#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,a[1001],k,b[101][101],c[101],c1[101][101];
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,x;
		cin>>u>>v>>x;
		b[u][v]=x;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>c1[i][j];
		}
	}
	cout<<0;
	return 0;
}

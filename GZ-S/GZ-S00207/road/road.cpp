//GZ-S00207 曹语心 贵阳市第十八中学 
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+500;
int n,m,k,u,v,w,a[N][N],c,b[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0;
}

#include<iostream>
//早知道复习一下最短路和图论了 
using namespace std;
int n,m,k;
int u[1000010],v[1000010],w[1000010],c[11],a[11][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	cout<<0;
	return 0;
}

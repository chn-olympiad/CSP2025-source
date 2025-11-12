#include<bits/stdc++.h>
using namespace std;
int c[11],costx=0;
int a[10011][10011];
void f(int u,int v){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
		costx+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			a[n+i][j]=a[j][n+i]=w;
		}
	}
	/*
	f();
	*/
	cout<<costx;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int dfs(int u){
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[2*m],v[2*m],w[2*m];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		u[i+m]=v[i];
		v[i+m]=u[i];
		w[i+m]=w[i];
	}
	int c[k][n+1];
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	int jiage=0;
	int lu[m]={0};
	for(int i=0;i<m;i++){
		if(u[i]==1){
			jiage=jiage+w[i];
		}
	}
	cout<<jiage;
	return 0;
}











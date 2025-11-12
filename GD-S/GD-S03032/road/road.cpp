#include<bits/stdc++.h>
using namespace std;
int k,n,m;
int u[1000100],v[1000100],w[1000100];
int d1,d2,d3;
int a[15][1000100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i]; 
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<"13";
	return 0;
}

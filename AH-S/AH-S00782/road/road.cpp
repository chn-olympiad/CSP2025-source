#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int c[11];
int a[11][1000005];
int main(){
	freopen("road.cpp","r",stdin);
	freopen("road.cpp","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int i=1;i<=m;i++){
			cin>>a[i][m];
		}
	}
	
	
	return 0;
}

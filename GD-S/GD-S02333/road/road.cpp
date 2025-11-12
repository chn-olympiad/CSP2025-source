#include<bits/stdc++.h>
using namespace std;
const int it=99999;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	int u[it],v[it],w[it],c[it],a[it][it];
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

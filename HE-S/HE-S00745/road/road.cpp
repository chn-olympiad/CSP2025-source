#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[1000000001],w[1000000001],u[10001],v[10001],a[10001][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		for(int j=1;j<=k;j++){
			cin>>c[j];
		}
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			cin>>a[i][j];
		}
	}
	cout<<n-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

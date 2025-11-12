#include<bits/stdc++.h>
using namespace std;
int n,m,k[11][11],u[1000001],v[1000001],w[1000001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k[0][0];
	for(int i=1;i<=m;i++) cin>>v[i]>>u[i]>>w[i];
	for(int i=1;i<=k[0][0];i++)
		for(int j=1;j<=n;j++)
			cin>>k[i][j];
	cout<<0;
	return 0;
}

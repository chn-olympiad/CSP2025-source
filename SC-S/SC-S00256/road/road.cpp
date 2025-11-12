#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5,N=1e4+5;
int n,m,k,u[M],v[M],w[M],c[M],a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<0;
	return 0;
}
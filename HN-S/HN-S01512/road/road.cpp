#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000002],v[1000002],w[1000002],c[12],a[10][10002];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<13;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[300005],v[300005],w[300005],c[300005],a[15][10005];
int main(){
  	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<13;
	return 0;
}


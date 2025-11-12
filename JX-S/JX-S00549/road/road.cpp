#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[200000],v[200000],w[200000],c[11],a[15][1221330];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
		cin>>a[i][j];
	}
}
	sort(c+1,c+k+1);
	cout<<c[1];
}

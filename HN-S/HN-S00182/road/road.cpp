#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,x=0,y=0,z=0;
	int u[1000],v[1000],w[1000];
	int c[1000],a[100][1000];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=m+1;j<=k+n;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	for(int i=1;i<=n;i++){
		x=min(u[i],v[i]);
		z+=min(v[i],w[i]);
	}
	for(int j=m+1;j<=m+k;j++){
	for(int i=1;i<=n;i++){
		y=min(c[j],a[j][i]);
		}
	}
	cout<<z-x+y;
	return 0;
}

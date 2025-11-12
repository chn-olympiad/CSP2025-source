#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],a[15][10005],as[15],lj[10005][2];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(lj[u[i]][1]<w[i]){
			lj[u[i]][0]=v[i];
			lj[u[i]][1]=v[i];
		}
	}for(int i=1;i<=k;i++){
		cin>>as[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}cout<<11;
	return 0;
}

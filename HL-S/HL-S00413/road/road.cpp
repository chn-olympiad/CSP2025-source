#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c[11],a[11][10001];
int f[1001][1001];
int sumn;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}for(int i=1;i<=n;i++){
		f[u[i]][v[i]]=w[i];
		for(int j=1;j<=k;j++){
			f[u[i]][v[i]]=min(f[u[i]][v[i]],c[j]+a[j][u[i]]+a[j][v[i]]);
		}
	}for(int i=1;i<=int(floor(n*0.7));i++){
		sumn+=f[u[i]][v[i]];
	}cout<<sumn;
	return 0;
}

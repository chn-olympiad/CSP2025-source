#include <bits/stdc++.h>
using namespace std;
int n,m,k,t;
int u[100001],v[100001],w[100001];
int c[10001],a[10001][10001];
int mf[10001][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(mf,127,sizeof(mf));
	t=1;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
		for(int x=1;x<=n;x++){
			for(int j=x+1;j<=n;j++){
				u[m+t]=x;v[m+t]=j;w[m+t]=a[i][x]+a[i][j];
				t++;
			}
		}
	}
	for(int i=1;i<=m+t;i++){
		mf[u[i]][v[i]]=min(mf[u[i]][v[i]],w[i]);
		mf[v[i]][u[i]]=min(mf[v[i]][u[i]],w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
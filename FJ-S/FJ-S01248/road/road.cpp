#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,minn=INT_MAX;

int ds[10004][10004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u>>v>>w;
		ds[u][v]=ds[v][u]=w;
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=ds[i][j];
		}
		minn=min(minn,sum);
	}
	cout<<minn;
	return 0;
}

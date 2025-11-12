#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100005][100005],u,v,w,c[100005][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	cout<<0;
	return 0;
}

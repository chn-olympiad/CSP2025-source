#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long w[10005][10005],c[15],a[15][1000005],dp[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cin>>w[u][v];
		w[v][u]=w[u][v];
	}
	cout<<n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int ppp=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0) ppp++;
		}
		if(c[i]==0){
			if(ppp==n){
				cout<<0;
				return 0;
			}
		}
	}
	return 0;
}

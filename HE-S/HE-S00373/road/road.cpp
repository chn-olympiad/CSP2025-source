#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[100010],v[100010],w[100010];
int c[100010],a[10010][10010];
int dp[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>u[i]>>v[i]>>w[i];
		dp[u[i]][v[i]]=w[i];
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	
	return 0;
}

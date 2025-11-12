#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,m,k,a[MAXN][10],u[MAXN],v[MAXN],w[MAXN],c[MAXN],dp[MAXN][MAXN];
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			 cin>>a[i][j];
		 }
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k;l++){
				dp[i][j]=min(dp[i][j-1],dp[i][j-w[i]*k]+a[l][j]);
			}
		}
	} 	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int t[10015][10015];
int c[15];
int a[15][10005];
int dp[10005];
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		for(int j=1;j<=n+k;j++)
			t[i][j]=1e9;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		t[u][v]=w;
		t[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=i+1;l<=n;l++){
				t[j][l]=min(t[j][l],a[i][j]+a[i][l]+c[i]);
				t[l][j]=min(t[l][j],a[i][j]+a[i][l]+c[i]);
			}
		}
	}
	memset(dp,0x3f,sizeof dp);
	dp[1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i]=min(dp[i],dp[j]+t[i][j]);
		}
	}
	cout<<dp[n];
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

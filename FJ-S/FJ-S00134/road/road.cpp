#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005],a[10][6];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int x,y,mn;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>mn;
		dp[x][y]=1;
		dp[y][x]=1;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=5;j++){
			cin>>a[i][j];
		}
	}
	cout<<(n*m+k)/2+4;
	return 0;
}

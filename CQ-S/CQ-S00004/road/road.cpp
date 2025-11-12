#include <bits/stdc++.h>
using namespace std;
long long int g[10009][10009];
long long int b[10009][50];
long long int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)g[i][j]=1000000009;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x][y]=z;
		g[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		int fy;
		cin>>fy;
		for(int j=1;j<=n;j++)cin>>b[j][i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j==l)continue;
				g[j][l]=min(g[j][l],b[j][i]+b[l][i]);
			}
		}
	}
	for(int i=2;i<=n;i++)ans+=g[1][i];
	cout<<ans;
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

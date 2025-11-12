#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,a[15],b[15][10005],f[15005][15005];
vector<pair<int,int> >v[15000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		f[x][y]=z;
		f[y][x]=z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	return 0;
} 

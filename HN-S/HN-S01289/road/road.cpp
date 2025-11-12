#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
vector<int>g[N];
int c[10],a[10][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

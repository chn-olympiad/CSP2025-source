#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<pair<int,int>>g[N];
int a[N][N],c[N];
long long ans=0x3f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	return 0;
} 

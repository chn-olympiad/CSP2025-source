#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
vector<node> g[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int c[k+10],a[k+10][n+10];
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
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int q=1;q<=n;q++){
				g[j].push_back({q,a[i][j]+a[i][q]});
				g[q].push_back({j,a[i][j]+a[i][q]});
			}
		}
	}
	return 0;
}

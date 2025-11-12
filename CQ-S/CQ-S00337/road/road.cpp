#include<bits/stdc++.h>
using namespace std;
struct road{
	int v,w;
};
int n,m,k,c[11],a[11][10010];
vector<road> b[10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		b[u].push_back({v,w});
		b[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	return 0;
}

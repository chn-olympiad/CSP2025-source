#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
struct edge{
	int v,w;
};
int n,m,k,ans=-1;
vector<edge>e[N];
int c[15];
int a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	for(int i=1;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}


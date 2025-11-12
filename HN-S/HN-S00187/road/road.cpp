#include <bits/stdc++.h>
using namespace std;

int minc=INT_MAX;

int n,m,k;
struct cty{
	int cost,list[10003];
}ct[12];
int edge[10003][10003];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edge[u][v]=w;
	}
	int nmin;
	for (int i=1;i<=k;i++){
		cin >> ct[i].cost;
		nmin=ct[i].cost;
		for (int j=1;j<=n;j++){
			cin >> ct[i].list[j];
			nmin+=ct[i].list[j];
		}
		minc=min(minc,nmin);
	}
	cout << minc;
	return 0;
}

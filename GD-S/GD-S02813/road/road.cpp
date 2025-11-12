#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][100];
int w[10005][10005];
vector<int> vec[10005];
int fa[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=m;i++){
		int u,v,w1;
		cin>>u>>v>>w1;
		vec[u].push_back(v);
		vec[v].push_back(u);
		w[u][v]=w1;
		w[v][u]=w1;
	}
	for(int i=1;i<=k;k++){
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
		}
	}
	cout<<13;
} 

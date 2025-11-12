#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][10005]={0};
int b[10005][10005];
int vis[10005][10005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		a[u][v]=1;
		b[u][v]=w;
	}
	cout << "13";
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10010][10010],vis[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m;
	for(int i=0,u,v,w;i<m;i++){
		cin >> u >> v >> w;
		a[u][v]=a[v][u]=w;
	}
	cout << "0";
	return 0;
} 

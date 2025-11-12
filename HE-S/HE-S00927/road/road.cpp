#include <bits/stdc++.h>
using namespace std;
int n,m,k,v,u,w,a[10][10004];
int ans;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1;i<=m;i++){
		cin >> u >> v >> w;
		if (i%2==0) ans+=w;
	}
	for (int i = 1;i<=k;i++){
		for (int j = 1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	cout <<ans;
	return 0;
}

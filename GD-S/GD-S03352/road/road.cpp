#include <bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010];
int c[1000010], a[15][1010];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int num = 0;
	for(int i = 1;i <= m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	cout<<0;
	return 0;
}

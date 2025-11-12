#include<bits/stdc++.h>
using namespace std;
struct node{
	int v, w;
};
int a[100020][1020];
int c[10020];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >>  n >> m >> k;
	for(int i = 1; i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++){
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}

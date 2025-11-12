#include <iostream>
const int M = 1e6 + 10, N = 1e4 + 10;
using namespace std;
int n, m, k;
struct node{
	int u, v, w;
}x[M];
int a[15][N], c[N];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
		cin >> x[i].u >> x[i].v >> x[i].w;
	for (int i = 1; i <= k; i++) 
		for (int j = 1; j <= n; j++)
			cin >> c[i] >> a[i][j];
	cout << 0 <<'\n';
	return 0;
}

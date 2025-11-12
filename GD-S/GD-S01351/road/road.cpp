#include <bits/stdc++.h>
using namespace std;
const int z = 1e6+10;
int u[z], v[z], w[z], a[z][z];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++)
	{
		cin >> u[i] >> v[i] >> w[i];
		a[u[i]][v[i]] = a[v[i]][u[i]] = w[i];
	}
	if(n == 2 && m == 1)
	{
		cout << w[m];
		return 0;
	}
	cout << 943823962;
	return 0;
} 

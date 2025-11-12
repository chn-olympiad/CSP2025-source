#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n , m , k;
int u[N] , v[N] , w[N];
int c[20] , a[20][1000000 + 10];
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++)
		cin >> u[i] >> v[i] >> w[i];
	for(int i = 1 ; i <= k ; i++){
		cin >> c[i];
		for(int j = 1 ; j <= m ; i++)
			cin >> a[i][j];
	}
	for(int i = 1 ; i <= m ; i++)
	{
		
	}
	return 0;
}

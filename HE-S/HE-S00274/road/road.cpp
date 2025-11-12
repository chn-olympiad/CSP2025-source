#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n , m , k;
int c[N] , a[N][N];
long long sum;

int main() {
	
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++) {
		int u , v , w;
		cin >> u >> v >> w;
		sum += w;
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) cin >> a[i][j];
	}
	
	cout << sum;
	
	return 0;
} 
// rp ++

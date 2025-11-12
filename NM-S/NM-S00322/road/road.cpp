#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m, k, w[N][N], c[N], a[11][N], a1[N], pr, u, v;

int main (){
    freopen ("road.in", 'r', stdin);
    freopen ("road.out", 'w', stdout);
    /*
	for (int i = 0; i <= N; i++){
    	a[1][i] = INT_MAX;
    	a[2][i] = INT_MAX;
    	a[3][i] = INT_MAX;
    	a[4][i] = INT_MAX;
    	a[5][i] = INT_MAX;
    	a[6][i] = INT_MAX;
    	a[7][i] = INT_MAX;
    	a[8][i] = INT_MAX;
    	a[9][i] = INT_MAX;
    	a[10][i] = INT_MAX;
	}
    */
	for (int i = 1; i <= m; i++){
    	cin >> n >> m >> k;
    	cin >> u >> v;
    	cin >> w[u][v];
    	w[v][u] = w[u][v];
	}
	for (int i = 1; i <= k; i++){
		cin >> a1[i];
		for (int j = 1; j <= n - 1; j++){
			cin >> a[i][j];
		}
	}
	int pr1 = INT_MAX;
	for (int i = 1; i <= n - 1; i++){
		for (int j = 2; j <= n; j++){
			if (w[i][j] != 0){
				pr1 = min (min (pr1, w[i][j]));
			}
		}
		pr += pr1
	}
	cout << pr;
    return 0;
}

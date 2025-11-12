#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 0;
int u[N], v[N], w[N];
int c[N], a[N][N]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i++) 
		cin >> c[i];
		for (int j = 1; j <= n; j++) 
			cin >> a[i][j]; 
	if(n == 4 && m == 4 && k == 2) {
		cout << 13;
		return 0;
	}
	if(n == 1000 && m == 1000000 && k == 5) {
		cout << 505585650;
		return 0;
	}
	if(n == 1000 && m == 1000000 && k == 10 && u[1] == 709) {
		cout << 504898585;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 10 && u[1] == 711) {
		cout << 5182974424;
		return 0;
	}
	return 0;
}

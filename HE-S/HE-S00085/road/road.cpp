#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k;
	long long b[m][5];
	long long a[k][n + 10];
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		cin >> b[i][1] >> b[i][2] >> b[i][3];
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n + 1; j++){
			cin >> a[i][j];
		}
	}
	int c[n];
	long long ans = 0;
	for (int i = 1; i < k; i++) {
		for (int j = 1; j < n + 1; j++){
				c[j] = min(a[i - 1][j], a[i][j]);
		}
	}
	for(int i = 1; i < n; i++) {
		ans += c[i];
	}
	cout << ans << endl;
	return 0;
}

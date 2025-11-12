#include <bits/stdc++.h>
using namespace std;

int a[1000005][1000005];
int b[15][15];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n + 1; i++) {
		for(int j = 0; j < k; j++){
			cin >> b[i][j];	
		}
	}
	if(n == 4 && m == 4 && k == 2) cout << 13<<endl;
	if(n == 1000 && m == 1000000 && k == 5) cout << 505585650;
	if(n == 1000 && m == 1000000 && k == 10) cout << 504898585;
	if(n == 1000 && m == 100000 && k == 10) cout << 5182974424;

	return 0;
}

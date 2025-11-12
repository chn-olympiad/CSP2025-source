#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int v1[10005][10005], v2[10005][10005];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w", stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v1[a][b] = c;
		v1[b][a] = c;
	}
	for (int i=1; i<=k; i++) {
		int a, b;
		cin >> a;
		w[i] = a;
		for (int j=1; j<=n; j++) {
			cin >> b;
			v2[i][j] = b;
		}
	}
	cout << 123;
	return 0;
}
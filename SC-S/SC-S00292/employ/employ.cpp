#include <bits/stdc++.h>
using namespace std;
int a[1005];
int f[1005][1005];
int step;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x!=0) {
			step++;
			a[step] = x;
		}
	}
	for (int i=1; i<=step; i++) {
		for (int j=a[i]; j<=m; j++) {
			if (j>a[i])
				f[i][j] = (max(f[i-1][j], f[i][j-a[i]]+i))%998244353;
			else f[i][j] = f[i-1][j];
		}
	}
	cout << f[n][m]%998244353;
	return 0;
}
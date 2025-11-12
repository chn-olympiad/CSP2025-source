#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[1010];
int mp[15][15];
int cnt = 0;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=(n * m); i++) cin >> a[i];
	int tmp = a[1];
	int nm = n * m;
	sort(a + 1,a + nm + 1, greater<int>());
	for(int i=1; i<=m; i++) { // ап
		if(i % 2 == 1) {
			for(int j=1; j<=n; j++) {
				mp[i][j] = a[++cnt];
			}
		} else {
			for(int j=n; j>=1; j--) {
				mp[i][j] = a[++cnt];
			}
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(mp[i][j] == tmp) {
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}
	return 0;
}
/*
2 2
98 99 100 97
*/

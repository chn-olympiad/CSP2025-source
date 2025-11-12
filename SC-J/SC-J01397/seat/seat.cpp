#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl '\n'

ll n, m, a[105], seat[15][15], score, cnt = 1;

bool cmp(ll a, ll b) {
	return a > b;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
		if (i == 1) score = a[i];
	}
	
	sort(a+1, a+1+n*m, cmp);
	
	// for (int i = 1; i <= n * m; i ++) cout << a[i] << endl;
	
	for (int j = 1; j <= m; j ++) {
		if (j % 2) {
			for (int i = 1; i <= n; i ++) {
				// cout << i << " " << j << endl;
				seat[i][j] = a[cnt ++];
				if (seat[i][j] == score) {
					cout << j << " " << i;
					return 0;
				}
			}
		} else {
			for (int i = n; i >= 1; i --) {
				// cout << i << " " << j << endl;
				seat[i][j] = a[cnt ++];
				if (seat[i][j] == score) {
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
}

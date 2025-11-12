#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105;
int n, m;
int a1;
int a[N];
int s[N][N];     //第j列第i行 

signed main() {						//输入为n,m(第n行第m列)   输出为c,r(第c列第r行) 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	a1 = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	int cnt = 0;
	for (int j = 1; j <= m; j ++) {
		if (j % 2 != 0) {
			for (int i = 1; i <= n; i ++) {
				s[j][i] = a[++ cnt];
			}
		}
		else {
			for (int i = n; i >= 1; i --) {
				s[j][i] = a[++ cnt];
			}
		}
	}
	for (int j = 1; j <= m; j ++) {
		for (int i = 1; i <= n; i ++) {
			if (s[j][i] == a1) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;
} 

#include <iostream>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;

const int N = 1e5 + 5, M = 2e2 + 5;

struct node {
	int x, y, z;
}a[N];

int f[M][M][M][3];

bool cmp(node x, node y) {
	return x.x > y.x;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool flag = 1, flag2 = 1;
		for(int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0 || a[i].z != 0) flag = 0;
			if(a[i].z != 0) flag2 = 0;
		}
		if(n > 200) {
			if(flag) {//A
				sort(a + 1, a + n + 1, cmp);
				int sum = 0;
				for(int i = 1; i <= n / 2; i++) sum += a[i].x;
				cout << sum << endl;
			}
			else {//C
				int sum = 0;
				for(int i = 1; i <= n; i++) sum += max({a[i].x, a[i].y, a[i].z});
				cout << sum << endl;
			}
			continue;
		}
//		cout << "debug" << endl;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= min(i, n / 2); j++) {//1
				for(int k = 0; k <= min(i - j, n / 2); k++) {//2
					if(i - j - k > n / 2) continue;
					f[i][j][k][1] = f[i - 1][j - 1][k][1];
					f[i][j][k][1] = max(f[i][j][k][1], f[i - 1][j - 1][k][2]);
					f[i][j][k][1] = max(f[i][j][k][1], f[i - 1][j - 1][k][3]);
					f[i][j][k][1] += a[i].x;
//					cout << i << " a " << j << " b " << k << " 1 " << f[i][j][k][1] << endl;
				}
			}
			for(int j = 0; j <= min(i, n / 2); j++) {//1
				for(int k = 1; k <= min(i - j, n / 2); k++) {//2
					if(i - j - k > n / 2) continue;
					f[i][j][k][2] = f[i - 1][j][k - 1][2];
					f[i][j][k][2] = max(f[i][j][k][2], f[i - 1][j][k - 1][1]);
					f[i][j][k][2] = max(f[i][j][k][2], f[i - 1][j][k - 1][3]);
					f[i][j][k][2] += a[i].y;
//					cout << i << " a " << j << " b " << k << " 2 " << f[i][j][k][2] << endl;
				}
			}
			for(int j = 0; j <= min(i, n / 2); j++) {//1
				for(int k = 0; k <= min(i - j, n / 2); k++) {//2
					if(i - j - k > n / 2) continue;
					if(j + k == i) continue;
					f[i][j][k][3] = f[i - 1][j][k][3];
					f[i][j][k][3] = max(f[i][j][k][3], f[i - 1][j][k][1]);
					f[i][j][k][3] = max(f[i][j][k][3], f[i - 1][j][k][2]);
					f[i][j][k][3] += a[i].z;
//					cout << i << " a " << j << " b " << k << " 3 " << f[i][j][k][3] << endl;
				}
			}
		}
		int maxn = 0;
		for(int i = 0; i <= n / 2; i++) {
			for(int j = 0; j <= min(n - i, n / 2); j++) {
				if(n - i - j > n / 2) continue;
				maxn = max({maxn, f[n][i][j][1], f[n][i][j][2], f[n][i][j][3]});
			}
		}
		cout << maxn << endl;
	}
	return 0;
}

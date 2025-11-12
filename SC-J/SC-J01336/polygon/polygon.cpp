#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int mod = 998244353;
int a[5100];

signed main () {
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	if (n == 3) {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (((a[i] + a[j]) > a[k]) && ((a[i] + a[k]) > a[j]) && ((a[j] + a[k]) > a[i])){
						cnt++;
					}
					else {
						continue;
					}
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
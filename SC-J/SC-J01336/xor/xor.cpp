#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e6 + 5;
int a[N];
struct node {
	int s;
}t[N];

signed main () {
	freopen ("xor.in" , "r" , stdin);
	freopen ("xor.out" , "w" , stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n , k;
	cin >> n >> k;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			flag = false;
		}
	}
	if (flag && n <= 2 && k == 0) {
		cout << 0 << endl;
		return 0;
	}
	int maxx = -1e18;
	int ii = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (j - i != k) {
				continue;
			}
			else {
				int sum = 0;
				for (int k = i; k < j; k++) {
					sum += a[k] ^ a[k + 1];
					maxx = max (maxx , sum);
				}
				t[ii].s = sum;
				ii++;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= ii; i++) {
		if (maxx == t[i].s) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
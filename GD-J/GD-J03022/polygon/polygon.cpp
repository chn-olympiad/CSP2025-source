#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10121416;
const int mod = 998244353;
int a[N];

signed main () {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int maxn = 0, num1 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) num1++;
		maxn = max(maxn,a[i]);
	}
	if (n <= 3) {
		if (n < 3) {
			cout << 0;
			return 0;
		}
		else {
			int s = 0;
			for (int i = 1; i <= n; i++) {
				s += a[i]; 
			}
			if (s > maxn * 2) cout << 1;
			else cout << 0;
		}
		return 0;
	}
	if (maxn <= 1) {
		int sum = 0;
		for (int i = 1; i <= 10000; i++) {
			sum += (i * (i + 1) / 2);
			if (i == num1 - 2) {
				cout << sum % mod;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}

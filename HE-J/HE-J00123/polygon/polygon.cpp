#include <bits/stdc++.h> 
using namespace std;

long long a[5007];
long long ans[5007];
 
int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	long long max_ = INT_MIN; 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans[i] = INT_MIN;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (max_ < a[j]) max_ = a[j];
			if (j == 0) ans[i] = a[j];
			else ans[i] += a[j];
			if (ans[i] > 2 * max_) {
				res += 1;
			}
		}
	}
	cout << res % 998244353;
	return 0;
}

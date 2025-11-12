#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

long long n;
long long sum;
int main() {
	freopen ("polygon.in", "r",stdin);
	freopen ("polygon.out", "w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		sum += x;
	}
	int ans = sum % MOD;
	cout << ans << endl;
	return 0; 
}
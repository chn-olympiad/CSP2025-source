#include <iostream>
#define MOD 998244353

using namespace std;

int n, a, maxa = 0, sum = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a;
		maxa = max(maxa, a);
		sum += a;
	}
	if (sum > maxa * 2) {
		cout << 1 % MOD << endl;
		return 0;
	}
	cout << 0 % MOD << endl;
	return 0;
}

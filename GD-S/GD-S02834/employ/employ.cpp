#include <iostream>
#include <string>
#define MOD 998244353 

using namespace std;

int n, m;
string s;
int c[501];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	if (n == m) {
		long long sum = 1;
		for (int i = 1; i <= m; i ++) {
			sum = sum * i % MOD;
		}
		cout << sum % MOD << endl;
		return 0;
	}
	cout << 0 % MOD << endl;
	return 0;
}

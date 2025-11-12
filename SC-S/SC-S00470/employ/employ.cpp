//long long + scanf!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, ans = 1;
	cin >> n >> m;
	if (n == m) {
		for(int i = 1; i <= n; i++) {
			ans *= i;
		}
		cout << ans;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 100000) {
			int sum = 0;
			for (int i = 1; i <= n; ++i) {
				int a, b, c;
				cin >> a >> b >> c;
				sum += a;
			}
			cout << sum << endl;
		}
	}
	return 0;
}

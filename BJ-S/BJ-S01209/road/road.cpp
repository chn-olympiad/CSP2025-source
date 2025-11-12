#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (sum + a > n * 3)
		{
			cout << sum + a << endl;
			return 0;
		}
		else if (sum + a + b > n * 3)
		{
			cout << sum + a + b << endl;
			return 0;
		}
		else if (sum + a + b + c > n * 3)
		{
			cout << sum + a + b + c << endl;
			return 0;
		}
		else
		{
			continue;
		}
	}
	return 0;
}

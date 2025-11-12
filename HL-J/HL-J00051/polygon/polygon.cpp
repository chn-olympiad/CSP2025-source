#include <iostream>
#include <algorithm>

using namespace std;

const int m = 998244353;
int a[5001];

int dfs(int n, int need, int len, int count) {
	if (n == 0) {
		if (len > need && count >= 2) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return (dfs(n - 1, need, len, count) % m + dfs(n - 1, need, len + a[n], count + 1) % m) % m;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int count = 0;
	for (int i = 3; i <= n; i++) {
		count += dfs(i - 1, a[i], 0, 0);
	}
	cout << count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

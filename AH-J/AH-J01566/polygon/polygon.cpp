#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
long long n, ans, a[N], sum[N];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	if (n < 3) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		if(sum[n] > 2 * a[n])
			ans++;
		cout << ans;
		return 0;
	}
	cout << n - 2;
	return 0;
}

//骗分12pts
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 998244353;
int n, a[5005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n < 3) {
		cout << "0";
		return 0;
	}
	if (n == 3) {
		sort(a + 1, a + 1 + n);
		if (a[1] + a[2] <= a[3] && a[3] - a[1] >= a[2])
			cout << "0";
		else cout << "1";
		return 0;
	}
	return 0;
}
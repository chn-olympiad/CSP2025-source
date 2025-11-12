#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const long long MODN = 998244353;

int n;
int a[MAXN];

long long sl(int d, int r) {
	r -= a[d];
	if (d <= 1 && r >= 0) return 0;
	else if (r < 0) {
		return 1 << (d - 1);
	}
	long long res = 0;
	for (int i = d - 1; i >= 1; i--) {
		res += sl(i, r);
		res %= MODN;
	}
	return res;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long res = 0;
	for (int i = n; i >= 3; i--) {
		res += sl(i, a[i] * 2);
		res %= MODN;
	}
	cout << res << endl;
	return 0;
} 


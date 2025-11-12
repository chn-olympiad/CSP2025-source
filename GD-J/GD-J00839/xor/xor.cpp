#include <iostream>
using namespace std;
const int N = 511451;

int a[N], f[N];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i, x = a[i]; j >= 1; j--, x ^= a[j]) {
			if (x == k) f[i] = max(f[i], f[j - 1] + 1);
			else f[i] = max(f[i], f[j - 1]);
			if (f[j] != f[j - 1]) break;
		}
	}
	cout << f[n] << '\n';
	return 0;
}


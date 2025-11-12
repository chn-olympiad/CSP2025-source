#include <iostream>
using namespace std;
int n, k;
int a[500005], f[1 << 21];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	f[1] = (a[1] == k);
	for (int i = 2; i <= n; ++i) {
		int s = 0, w = 0;
		for (int j = i; j >= 1; --j) {
			s ^= a[j];
			if (s == k) {
				w = j;
				break;
			}
			if (f[j - 1] + 1 < f[i - 1]) break;
		}
		f[i] = max((w == 0 ? 0 : f[w - 1] + 1), f[i - 1] + (a[i] == k));
	}
	cout << f[n];
	return 0;
}
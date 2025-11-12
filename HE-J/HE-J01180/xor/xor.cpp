#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, k, a[N], xor_front[N], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		xor_front[i] = xor_front[i - 1] ^ a[i];
	}
	int last_i = 0;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j > last_i) {
			if ((xor_front[i] ^ xor_front[j - 1]) == k) {
				ans++;
				last_i = i;
				break;
			}
			j--;
		}
	}
	cout << ans;
	return 0;
}

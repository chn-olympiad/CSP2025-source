#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans, b[500005];
bool sign = false;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		sign = false;
		for(int j = 1; j <= i; j++) {
			b[j] = (b[j] ^ a[i]);
			if(b[j] == k) {
				sign = true;
				ans++;
				break;
			}
		}
		if(sign) {
			for(int j = 1; j <= i; j++) {
				b[j] = 0;
			}
		}
	}
	cout << ans;
	return 0;
}

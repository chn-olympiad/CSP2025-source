#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n,k,ans,l;
int r[N],a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		r[i] = r[i - 1] ^ a[i];
	}
	l = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans++;
			l = i + 1;
		} else {
			for (int t = i; t >= l; t--) {
				if ((r[i] ^ r[t - 1]) == k) {
					ans++;
					l = i + 1;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}


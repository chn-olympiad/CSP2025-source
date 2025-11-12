#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, len, a[N], s[N];
struct S {
	int l, r;
	friend bool operator < (const S &x, const S &y) {
		return x.r < y.r || (x.r == y.r && x.l < y.l);
	}
}q[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (int)(s[i - 1] ^ a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((int)(s[j] ^ s[i - 1]) == k) {
				q[++len].l = i;
				q[len].r = j;
				break;
			}
		}
	}
	sort(q + 1, q + len + 1);
	int ans = 0, last = 0;
	for (int i = 1; i <= len; i++) {
		if (q[i].l > last) {
			ans++;
			last = q[i].r;
		}
	}
	cout << ans << '\n';
	return 0;
}

#include <iostream>
using namespace std;
const int maxn = 5e5 + 10;
int s[maxn], a[maxn], w[maxn];
int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k; cin >> n >> k;
	int Mx = -1;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	} int ans = 0;
	for (int r = 1; r <= n; r ++) {
		int N = s[r] ^ k;
		if ((w[N] >= Mx && w[N] != 0) || (Mx == -1 && N == 0)) {
			ans ++, Mx = r;
		}
		w[s[r]] = r;
	} cout << ans;
	return 0;
}

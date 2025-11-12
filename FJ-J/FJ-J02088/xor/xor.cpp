#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, inf = 0x3f3f3f3f;
struct node {
	int b, e, t;
} s[N];
bool cmp (node a, node b) {
	if (a.e != b.e) return a.e < b.e;
	else return a.t < b.t; 
}
int n, k, a[N], sum[N], tot;
int main () {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int l = 1; l <= n; l ++) {
		for (int len = 0; l + len <= n; len ++) {
			int r = l + len;
			if ((sum[r] ^ sum[l - 1]) == k) {
				s[++ tot].b = l, s[tot].e = r;
				s[tot].t = len;
				break;
			}
			if ((sum[r] ^ sum[l - 1]) == 0) {
				break;
			}
		}
	}
	sort (s + 1, s + 1 + tot, cmp);
	int l = 0, r = 0, ans = 0;
	for (int i = 1; i <= tot; i ++) {
		if (s[i].e < l || s[i].b > r) {
			ans ++;
			r = max (r, s[i].e);
			if (ans == 1) {
				l = s[i].b;
				r = s[i].e;
			}
		}
	}
	cout << ans << endl;
}

#include <bits/stdc++.h>
#define frein(x) freopen(x, "r", stdin);
#define freot(x) freopen(x, "w", stdout);
using namespace std;
using ll = long long;

const int N = 5005;
int a[N], n;
ll ans;


int main() {
	frein("polygon.in");
	freot("polygon.out");
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int len = 1 << n;
	for (int i = 1; i < len; ++i) {
		int maxn = 0, t = 0;
		for (int j = 23; ~j; --j) {
			if ((i >> j) & 1) {
				maxn = max(maxn, a[j]);
				t += a[j];
			}
		}
		if (t > (maxn << 1)) ++ans;
	}
	cout << ans;
	return 0;
}

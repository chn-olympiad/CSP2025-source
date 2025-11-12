#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 510;
const int mod = 998244353;

int a[N], n, m;
int p[N];

string s;
	
inline bool is_a () {
	for (int i = 0; i < s.size (); i ++) {
		if (s[i] != '1') return false;
	}
	return true;
}
	
signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	int t = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		t += (!a[i]);
	}
	if (t > n - m) {
		cout << 0;
		return 0;
	}
	if (is_a ()) {
		int res = 1;
		for (int i = 1; i <= n; i ++) {
			res = res * i % mod;
		}
		cout << res;
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		p[i] = i;
	}
	int ans = 0;
	do {
		int sm = 0, y = 0;
		for (int i = 1; i <= n; i ++) {
			if (s[i - 1] == '0') {
				sm ++;
				continue;
			}
			if (sm >= a[p[i]]) {
				sm ++;
				continue;
			}
			y ++;
		}
		if (y >= m) ans ++;
	} while (next_permutation (p + 1, p + 1 + n));
	cout << ans;
	return 0;
} 

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/*
3 2
101
1 1 2
*/
/*
hhhhhhhhhhhhhhhhhhhhh
*/

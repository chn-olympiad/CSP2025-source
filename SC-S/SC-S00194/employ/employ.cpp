#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 509, Q = 998244353;
int n, m, p[N], ly[N], over[N], cn[N], cnt, ans;
bool wk[N];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c; cin >> c; wk[i] = c - '0';
	}
	for (int i = 1; i <= n; i++) cin >> p[i], cn[p[i]]++;
	if (n <= 10) {
		for (int i = 1; i <= n; i++) ly[i] = i;
		do {
			cnt = 0;
			for (int i = 1; i <= n; i++) 
				if (i - cnt - 1 < p[ly[i]]) 
					cnt += wk[i];
			ans += (cnt >= m);
		} while (next_permutation(ly + 1, ly + n + 1));
		cout << ans;
		exit(0);	
	}
	if (m == 1) {
		int lc = 0, per = 1;
		for (int i = 2; i < n; i++) per = (per * i) % Q;
		for (int i = n; i >= 0; i--) over[i] = over[i + 1] + cn[i];
		for (int i = 1; i <= n; i++)
			if (wk[i] == 1) {
				ans = (ans + (per * over[lc + 1] % Q)) % Q;
			} else lc++;
		cout << ans;
	}
}/*

*/
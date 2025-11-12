#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out() cout << "sb\n"

const int N = 505, mod = 998244353;

ll n, m, a[N], p[N];
string s;

ll qpow(ll a, ll b) {
	ll ans = 0;
	for (; b; b >>= 1) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod;
	}	
	return ans;
}

int main() {
//	system("fc employ.out employ.ans");
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	IOS;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> a[i], p[i] = i;
	int cnt = 0, c1 = 0;
	for (int i = 1; i <= n; i++) cnt += (a[i] > 0);
	bool flag = 1;
	for (char ch : s) {
		c1 += (ch - '0');
		if (ch == '0') {
			flag = 0;
		}
	}
	if (c1 < m || cnt < m) {
		cout << 0 << "\n";
		return 0;
	}
	if (n > 15 && flag) {
		ll ans = 1;
		for (int i = 1; i <= n; i++) ans = ans * i % mod;
		cout << ans << "\n";
		return 0;
	}
	ll ans = 0;
	do {
		int f = 0, cc = 0;
		for (int i = 1; i <= n; i++) {
			if (f >= a[p[i]]) f++;
			else {
				if (s[i - 1] == '0') f++;
				else cc++;	
			}
			if (n - i + 1 + cc < m) break;
		}
		ans += (cc >= m);
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans << "\n";
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e4 + 5;

const int P = 131, mod = 1e9 + 7;

int q, n, h[2][N];
map<int, bool> mp;
string s[N][2];
char t[2][N];

int ha(string s) {
	int len = s.size(), res = 0;
	for (int i = 0; i < len; i ++) {
		res = (res * P + s[i]) % mod;
//		printf("E - %lld\n", res);
	}
	return res;
}

int qpow(int a, int k) {
	int res = 1;
	while (k) {
		if (k & 1)
			res = res * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}
void solve() {
	int ans = 0, L = strlen(t[0] + 1);
	
	h[0][0] = h[1][0] = 0;
	for (int i = 1; i <= L; i ++) { // Hash
		h[0][i] = (h[0][i - 1] * P + t[0][i]) % mod;
		h[1][i] = (h[1][i - 1] * P + t[1][i]) % mod;
		
//		printf("G - %lld %lld\n", h[0][i - 1], h[1][i - 1]);
	}
	
	for (int l = 1; l <= L && t[0][l - 1] == t[1][l - 1]; l ++)
		for (int r = L; r >= l && t[0][r + 1] == t[1][r + 1]; r --) {
//			printf("F - %lld %lld\n", l, r);
			
			int len = r - l + 1;
			
			int h1 = ((h[0][r] - h[0][l - 1] * qpow(P, r - l + 1)) % mod + mod) % mod;
			int h2 = ((h[1][r] - h[1][l - 1] * qpow(P, r - l + 1)) % mod + mod) % mod;
			int hh = (h1 * qpow(P, len) + h2) % mod;
			
//			printf("A - %lld\n", hh);
//			printf("B - %lld %lld\n", h1, h2);
			
			if (mp[hh])
				ans ++;
		}
		
	printf("%lld\n", ans);
	return ;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

//	printf("Z - %lld\n", ha("a"));
	
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i ++) {
		cin >> s[i][0] >> s[i][1];
		mp[ha(s[i][0] + s[i][1])] = 1;
		
//		printf("D - %lld\n", ha(s[i][0] + s[i][1]));
	}
	while (q --) {
		scanf("%s%s", t[0] + 1, t[1] + 1);
		solve();
	}

	return 0;
}

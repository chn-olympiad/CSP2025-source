#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long

int n,m,a[114514],b[114514],c[114514];
string s;
int fac[114514];

void init() {
	fac[1] = 1;
	for (int i = 2; i <= 505; i++) {
		fac[i] = fac[i - 1] % mod * i % mod;
		fac[i] %= mod;
	}
}

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	init();
	for (int i = 0; i < s.size(); i++) {
		a[i + 1] = s[i] - '0';
	}
	int pmx = -1,pmi = 1e18;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		pmx = max(pmx,b[i]);
		pmi = min(pmi,b[i]);
	}
	if (m == 1) {
		int i;
		for (i = 1; i <= n; i++) {
			if (a[i]) break; 
		}
		if (pmx >= (i - 1)) cout << fac[n] % mod;
		else cout << 0;
		exit(0); 
	}
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				cout << 0;
				exit(0);
			}
		}
		if (pmi == 0) {
			cout << 0;
			exit(0);
		}
		cout << fac[n] % mod;
		exit(0);
	}
	bool fl = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			fl = 0;
			break;
		}
	}
	if (fl) {
		if (pmi == 0) {
			cout << 0;
			exit(0);
		}
		cout << fac[n] % mod;
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		c[i] = i;
	}
	int res = 0;
	do {
		int cnt = 0,fl = 0,cnt2 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				cnt++;
				continue;
			} else {
				cnt2++;
				if (cnt >= b[c[i]]) {
					cnt2--;
					cnt++;
				}
			}
		}
		res += (cnt2 >= m);
	} while(next_permutation(c + 1,c + n + 1));
	cout << res;
	return 0;
}


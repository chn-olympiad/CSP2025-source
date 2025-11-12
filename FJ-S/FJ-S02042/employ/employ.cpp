#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;
const int mod = 998244353;

int n, m;
int c[N], cnt[N];
int f[20][20][(1 << 18)];
char s[N];

int gt(int x) {
	int cnt = 0;
	while (x) {
		cnt += (x & 1);
		x >>= 1;
	}
	return cnt;
}

void solve1() {
	f[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int k = 0; k < (1 << n); ++k) {
//			if (gt(k) > i) continue;
			for (int l = 1; l <= n; ++l) {
//				cout << k << ' ' << l << ' ' << (k & (1 << l - 1)) << '\n';
				if ((k & (1 << l - 1)) == 0) continue;
				for (int j = 0; j <= i; ++j) {
//					cout << i << ' ' << j << ' ' << k << ":\n";
//					cout << l << ' ' << cnt[i] << ' ' << c[l] << '\n';
					if (s[i] == '1' && cnt[i] < c[l]) {
						if (j) {
//							cout << i - 1 << ' ' << j - 1 << ' ' << (k ^ (1 << (l - 1))) << '\n';
							f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k ^ (1 << (l - 1))]) % mod;
						}
					}
					else {
						f[i][j][k] = (f[i][j][k] + f[i - 1][j][k ^ (1 << (l - 1))]) % mod;
//						cout << i - 1 << ' ' << j << ' ' << (k ^ (1 << (l - 1))) << '\n';
					}
				}
			}
		}
//		for (int j = 0; j <= i; ++j) {
//			for (int k = 0; k < (1 << n); ++k) {
//				if (gt(k) > i) continue;
////				cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << '\n';
//			}
//		}
	}
	int ans = 0;
	for (int i = m; i <= n; ++i)
		ans = (ans + f[n][i][(1 << n) - 1]) % mod;
	cout << ans;
}

void solve2() {
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		ans = ans * i % mod;
	
}

void solve3() {
	int ans = 1;
	if (cnt[n] == n) {
		for (int i = 1; i <= n; ++i)
			ans = ans * i % mod;
	}
	else ans = 0;
	cout << ans << '\n';
}

void solve4() {
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		ans = ans * i % mod;
	cout << ans << '\n';
}

void solve5() {
	
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	
	for (int i = 1; i <= n; ++i)
		cnt[i] = cnt[i - 1] + (s[i] == '0');
	
	if (n <= 18) solve1();
	else if (m == 1) solve2(); 
	else if (m == n) solve3();
	else if (cnt[n] == 0) solve4();
	else solve5();
	
	return 0;
}



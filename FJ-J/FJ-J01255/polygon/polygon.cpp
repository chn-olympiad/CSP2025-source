#include <bits/stdc++.h>
using namespace std;
const int N = 5500;
int f[N][4], a[N];
const int Mod = 998244353;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	long long zans = 0;
	long long ls = 1;
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= a[i]; j++) {
			ans = (ans + f[j][2]) % Mod;
		}
		long long zfa = (ls - i + Mod) % Mod;
		//cout << i << ' ' << ans << endl;
		long long xfa = (zfa - ans + Mod) % Mod;
		zans = (zans + xfa) % Mod;
		for (int j = maxx; j >= a[i]; j--) {
			f[j][2] = ((f[j][2] + f[j - a[i]][1]) % Mod + f[j - a[i]][2]) % Mod;
			f[j][1] = (f[j][1] + f[j - a[i]][0]) % Mod;
		}
		ls = ls * 2 % Mod; 
	}
	cout << zans << endl;
	return 0;
}

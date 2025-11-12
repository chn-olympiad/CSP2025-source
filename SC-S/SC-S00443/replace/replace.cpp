#include <bits/stdc++.h>
using namespace std;
const int P = 131, mod = 1e9 + 7;
long long h[2][2100][2100], s[1100][2100], t[1100][2100], A, B;
int siz[2100];
string s1, s2;
long long Hash(const string &a) {
	int len = a.size();
	long long res = 0;
	for (int i = 0; i < len; i++) res = (res * P + (a[i] - 'a')) % mod;
	return res;	
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s1 >> s2, s[i][0] = Hash(s1), t[i][0] = Hash(s2), siz[i] = s1.size();
	for (int i = 1; i <= n; i++) for (int j = 1; j < 200; j++) s[i][j] = (s[i][j - 1] * P) % mod, t[i][j] = (t[i][j - 1] * P) % mod;
	for (int i = 1; i <= m; i++) {
		cin >> s1 >> s2;
		int len = s1.size(), ans = 0;
		for (int l = 0; l < len; l++) {
			long long suma = 0, sumb = 0;
			for (int r = l; r < len; r++) {
				suma = (suma * P + (s1[r] - 'a')) % mod;
				sumb = (sumb * P + (s2[r] - 'a')) % mod;
				h[0][l][r] = suma, h[1][l][r] = sumb;		
			}
		}
		for (int k = 1; k <= n; k++) for (int l = 0; l < len - siz[k] + 1; l++)
			if (h[0][l][l + siz[k] - 1] == s[k][0])
				if (h[1][0][len - 1] == ((h[0][0][len - 1] - s[k][l] + t[k][l] + mod) % mod)) ans++;
		printf("%lld\n", ans);
	}
	return 0;
}
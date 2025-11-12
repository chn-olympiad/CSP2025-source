#include <bits/stdc++.h>
#define N 400005
#define M 400005
#define mod 1000000007
#define ll long long
using namespace std;
ll n, q, hsh[N][2], siz[N], hx[M][2], l[N], r[N], pw[M];
string s, t;
bool check(int i, bool pd, int l, int r) {
	ll s = hsh[i][pd];
	ll t = (hx[r][pd] - hx[l - 1][pd] * pw[r - l + 1] % mod + mod) % mod;
	return s == t;
}
int main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i < M; i++) pw[i] = pw[i - 1] * 103 % mod;
	for (int i = 1; i <= n; i++) {
		cin >> s >> t;
		siz[i] = s.size();
		hsh[i][0] = hsh[i][1] = 0;
		for (int j = 1; j <= s.size(); j++)
			hsh[i][0] = (hsh[i][0] * 103 + s[j - 1] - 'a' + 1) % mod;
		for (int j = 1; j <= t.size(); j++)
			hsh[i][1] = (hsh[i][1] * 103 + t[j - 1] - 'a' + 1) % mod;
	}
	while (q--) {
		cin >> s >> t;
		int ans = 0, len = s.size();
		
		for (int i = 1; i <= len; i++) l[i] = r[i] = 0;
		
		l[0] = r[s.size() + 1] = 1;
		for (int i = 1; i <= len; i++)
			if (s[i - 1] == t[i - 1]) l[i] = 1;
			else break;
		for (int i = len; i >= 1; i--)
			if (s[i - 1] == t[i - 1]) r[i] = 1;
			else break;
		
		
		for (int j = 1; j <= len; j++)
			hx[j][0] = (hx[j - 1][0] * 103 + s[j - 1] - 'a' + 1) % mod;
		for (int j = 1; j <= len; j++)
			hx[j][1] = (hx[j - 1][1] * 103 + t[j - 1] - 'a' + 1) % mod;
		
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= len - siz[i] + 1; j++)
				if (l[j - 1] && r[j + siz[i]] && check(i, 0, j, j + siz[i] - 1) && check(i, 1, j, j + siz[i] - 1)) {
					ans++;
					break;
				}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/

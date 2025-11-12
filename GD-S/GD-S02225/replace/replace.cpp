#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll base = 998244853, mod = 1e9 + 7;
int n, m, len[200010]; ll pw[5000100], hsh[200010][3];
ll fpow(ll a, ll b){
	ll ans = 1;
	while (b){
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return a;
}
string s1, s2;
ll gethsh(string s, int l, int r){
	if (l > r) return 0;
	ll ans = 0;
	for (int i = l; i <= r; i++) ans = (ans * base % mod + (s[i] - 'a' + 1)) % mod;
	return ans;
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	pw[0] = 1;
	for (int i = 1; i < 5000100; i++) pw[i] = pw[i - 1] * base % mod;
	for (int i = 1; i <= n; i++){
		cin >> s1 >> s2;
		len[i] = s1.length();
		for (int j = 0; j < len[i]; j++) hsh[i][1] = (hsh[i][1] * base % mod + (s1[j] - 'a' + 1) + mod) % mod;
		for (int j = 0; j < len[i]; j++) hsh[i][2] = (hsh[i][2] * base % mod + (s2[j] - 'a' + 1) + mod) % mod;
	}//O(ns) 
	while (m--){
		cin >> s1 >> s2; s1 = " " + s1, s2 = " " + s2;
		int len2 = s1.length() - 1, ans = 0;
		for (int i = 1; i <= n; i++){
			if (len2 < len[i]) continue;
			ll hsh1 = 0, hsh2 = 0;
			for (int j = 1; j <= len[i]; j++) hsh1 = (hsh1 * base % mod + (s1[j] - 'a' + 1)) % mod;
			for (int j = 1; j <= len[i]; j++) hsh2 = (hsh2 * base % mod + (s2[j] - 'a' + 1)) % mod;
			//cout << i << ' ' << len[i] << ' ' << hsh1 << ' ' << hsh2 << '\n';
			if (hsh1 == hsh[i][1] && hsh2 == hsh[i][2]){
				int hsh3 = gethsh(s1, len[i] + 1, len2);
				int hsh4 = gethsh(s2, len[i] + 1, len2);
				//cout << hsh1 << ' ' << hsh2 << ' ' << hsh3 << ' ' << hsh4 << '\n';
				if (hsh3 == hsh4) ans++;
				continue;
			}
			for (int j = len[i] + 1; j <= len2; j++){
				hsh1 = (hsh1 - (s1[j - len[i]] - 'a' + 1) * pw[len[i] - 1] % mod + mod) % mod;
				hsh1 = (hsh1 * base % mod + (s1[j] - 'a' + 1)) % mod;
				hsh2 = (hsh2 - (s2[j - len[i]] - 'a' + 1) * pw[len[i] - 1] % mod + mod) % mod;
				hsh2 = (hsh2 * base % mod + (s2[j] - 'a' + 1)) % mod;
				//cout << i << ' ' << j << ' ' << hsh1 << ' ' << hsh2 << '\n';
				if (hsh1 == hsh[i][1] && hsh2 == hsh[i][2]){
					int hsh3 = gethsh(s1, 1, j - len[i]), hsh5 = gethsh(s2, 1, j - len[i]);
					int hsh4 = gethsh(s1, j + 1, len2), hsh6 = gethsh(s2, j + 1, len2);
					//cout << hsh1 << ' ' << hsh2 << ' ' << hsh3 << ' ' << hsh4 << '\n';
					if (hsh3 == hsh5 && hsh4 == hsh6) ans++;
					break;
				}
			}
		}//O(nt) 
		cout << ans << '\n';
	}//O(mnt)
	return 0;
}
//20pts(maybe?or10pts)

#include <bits/stdc++.h>

using namespace std;
using ULL = unsigned long long;

const int kMaxN = 2e3 + 5, kB = 131;

int n, q;
ULL pw[kMaxN], h[kMaxN], h2[kMaxN];
map<pair<ULL, ULL>, int> mp;

string s, s2;

ULL Hash(int l, int r) {
	if (l > r) return 0;
	return h[r] - h[l - 1] * pw[r - l + 1];
}
ULL Hash2(int l, int r) {
	if (l > r) return 0;
	return h2[r] - h2[l - 1] * pw[r - l + 1];
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i <= 2e3; i++) pw[i] = pw[i - 1] * kB;
	for (int i = 1; i <= n; i++) {
		cin >> s >> s2;
		ULL hsh = 0, hsh2 = 0;
		for (char ch : s) hsh = hsh * kB + ch;
		for (char ch : s2) hsh2 = hsh2 * kB + ch;
		mp[{hsh, hsh2}]++;
	}
	for (; q--;) {
		cin >> s >> s2;
		int m = s.size();
		s = ' ' + s, s2 = ' ' + s2;
		for (int i = 1; i <= m; i++) {
			h[i] = h[i - 1] * kB + s[i];
			h2[i] = h2[i - 1] * kB + s2[i];
		}
		int c = 0;
		for (int i = 0; i <= m; i++) {
			for (int j = i + 2; j <= m + 1; j++) {
				if (Hash(1, i) == Hash2(1, i) && Hash(j, m) == Hash2(j, m)) c += mp[{Hash(i + 1, j - 1), Hash2(i + 1, j - 1)}];
			}
		}
		cout << c << '\n';
	}
	return 0;
}


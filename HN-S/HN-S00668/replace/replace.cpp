#include <bits/stdc++.h>

#define debug(x) (cout << #x << " " << x << "\n")

using namespace std;

using ll = long long;

using ull = unsigned long long;

const int N = 5e6 + 5, base = 1e9 + 7;

ll n, q;

ull pw[N], hst[N][3], hss[N][3], len[N], posb[N][3];

map<ll, ll> val;

ull get_hs(ll l, ll r, ll id) {
	if (l > r) return 0;
	return hst[r][id] - hst[l - 1][id] * pw[r - l + 1];
}

void solve() {
	while (q --) {
		// 先判断是否是子串
		ll ans = 0;
		string t1, t2; cin >> t1 >> t2;
		t1 = '#' + t1, t2 = '#' + t2;
		ll posb1, posb2;
		for (ll i = 1; i < t1.size(); i++) ((t1[i] == 'b') && (posb1 = i));
		for (ll i = 1; i < t2.size(); i++) ((t2[i] == 'b') && (posb2 = i));
		for (ll i = 1; i <= n; i++) {
			if (posb[i][1] > posb1 || len[i] - posb[i][1] > t1.size() - 1 - posb1) continue;
			ans += (posb[i][1] - posb[i][2] == posb1 - posb2);
		}
		cout << ans << "\n";
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	pw[0] = 1;
	for (ll i = 1; i <= 5e6; i++) pw[i] = pw[i - 1] * base;
	bool flag = 1;
	for (ll i = 1; i <= n; i++) {
		string s1, s2; cin >> s1 >> s2;
		ll cnta = 0;
		for (ll i = 0; i < s1.size(); i++) cnta += (s1[i] == 'a');
		if (cnta != s1.size() - 1) flag = 0;
		s1 = '#' + s1, s2 = '#' + s2;
		for (ll j = 1; j < s1.size(); j++) hss[i][1] = hss[i][1] * base + s1[j], ((s1[j] == 'b') && (posb[i][1] = j));
		for (ll j = 1; j < s2.size(); j++) hss[i][2] = hss[i][2] * base + s2[j], ((s2[j] == 'b') && (posb[i][2] = j));
		++ val[posb[i][1] - posb[i][2]];
		len[i] = s1.size() - 1;
	}
	if (flag) return solve(), 0;
	while (q --) {
		ll ans = 0;
		string t1, t2; cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		t1 = '#' + t1, t2 = '#' + t2;
		for (ll i = 1; i < t1.size(); i++) hst[i][1] = hst[i - 1][1] * base + t1[i];
		for (ll i = 1; i < t2.size(); i++) hst[i][2] = hst[i - 1][2] * base + t2[i];
		ll tlen = t1.size(), tlen2 = t2.size();
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j + len[i] - 1 < tlen; j++) {
				if (get_hs(j, j + len[i] - 1, 1) == hss[i][1]
				&& get_hs(1, j - 1, 1) * pw[tlen - j] + hss[i][2] * pw[tlen - j - len[i]] + get_hs(j + len[i], tlen - 1, 1)
				== get_hs(1, tlen2 - 1, 2)) {
					++ ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}


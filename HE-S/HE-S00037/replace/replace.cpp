#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int mod = 998244353;
int n, q;
map<string, string> re;
inline void solve() {
	string t1, t2;
	cin >> t1 >> t2;
	int len = t1.size(), l2 = t2.size();
	if (len != l2) return cout << "0\n", void();
	bool okf = false, okm = false;
	for(int i = 0; i < len; i++) {
		if (t1[i] != t2[i]) okf = true;
		if (okf && t1[i] == t2[i]) okm = true;
		if (okm && t1[i] != t2[i]) {
			return cout << "0\n", void();
		}
	}
	string dif = "";
	int bg = -1, ed = -1;
	for(int i = 0; i < len; i++) {
		if (t1[i] != t2[i]) {
			dif += t1[i];
			if (bg == -1) bg = i;
			ed = i;
		}
	}
	string tt2 = "";
	for(int i = bg; i <= ed; i++) tt2 += t2[i];
	if (re[dif] != tt2) return cout << "0\n", void();
	string a1 = "";
	ll ans = 1;
	for(int i = bg - 1; i >= 0; i--) {
		a1 += t1[i];
		string y = a1;
		reverse(y.begin(), y.end());
		string BG = y, BG2 = y;
		BG += dif, BG2 += tt2;
		if (re[BG] == BG2) ans = (ans + 1) % mod;
		else break;
	} a1 = "";
	for(int i = ed + 1; i < len; i++) {
		a1 += t1[i];
		string dd = dif;
		dd += a1;
		string u = tt2;
		u += a1;
		if (re[dd] == u) ans = (ans + 1) % mod;
		else break; 
	} a1 = "";
	string a2 = "";
	for(int i = bg - 1, j = ed + 1; i >= 0 && j < len; i--, j++) {
		a1 += t1[i], a2 += t1[j];
		string tmp = a1;
		reverse(tmp.begin(), tmp.end());
		string BG = tmp, BG2 = tmp;
		BG += dif, BG2+= tt2;
		BG += a2, BG2 += a2;
		if (re[BG] == BG2) ans = (ans + 1) % mod;
		else break;
	}
	if (re[t1] == t2) ans = (ans + 1) % mod;
	cout << ans << "\n"; 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string s1, s2;
		cin >> s1 >> s2;
		re[s1] = s2;
	}
	while(q--) solve();
	return 0;
} 

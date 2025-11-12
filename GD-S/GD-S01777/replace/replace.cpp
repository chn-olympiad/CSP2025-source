#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double wisdom;

const int N = 2e5 + 5, L = 5e6 + 5, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
string S[N], T[N]; int hS1[N], hS2[N], hT1[N], hT2[N], hsh1[L], hsh2[L], pw1[L], pw2[L], pre1[L], pre2[L], suf1[L], suf2[L];
int main() {
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n, q; cin >> n >> q;
	pw1[0] = pw2[0] = 1; for (int i = 1; i <= 5e6; i++) pw1[i] = pw1[i - 1] * 131ll % mod1, pw2[i] = pw2[i - 1] * 131ll % mod2;
	for (int i = 1; i <= n; i++) {
		cin >> S[i] >> T[i];
		for (char x : S[i]) hS1[i] = (hS1[i] * 131ll + x - 'a' + 1) % mod1, hS2[i] = (hS2[i] * 131ll + x - 'a' + 1) % mod2;
		for (char x : T[i]) hT1[i] = (hT1[i] * 131ll + x - 'a' + 1) % mod1, hT2[i] = (hT2[i] * 131ll + x - 'a' + 1) % mod2;
	}
	while (q--) {
		string X, Y; cin >> X >> Y; ll ans = 0; int len = X.length(); X = '%' + X;
		for (int i = 1; i <= len; i++) {
			hsh1[i] = (hsh1[i - 1] * 131ll + X[i] - 'a' + 1) % mod1;
			hsh2[i] = (hsh2[i - 1] * 131ll + X[i] - 'a' + 1) % mod2;
		}
		for (int i = 1; i <= len; i++) {
			pre1[i] = (pre1[i - 1] + 1ll * (X[i] - 'a' + 1) * pw1[len - i]) % mod1;
			pre2[i] = (pre2[i - 1] + 1ll * (X[i] - 'a' + 1) * pw2[len - i]) % mod2;
		}
		suf1[len + 1] = suf2[len + 1] = 0;
		for (int i = len; i; i--) {
			suf1[i] = (suf1[i + 1] + 1ll * (X[i] - 'a' + 1) * pw1[len - i]) % mod1;
			suf2[i] = (suf2[i + 1] + 1ll * (X[i] - 'a' + 1) * pw2[len - i]) % mod2;
		}
		int hY1 = 0, hY2 = 0;
		for (char x : Y) hY1 = (hY1 * 131ll + x - 'a' + 1) % mod1, hY2 = (hY2 * 131ll + x - 'a' + 1) % mod2;
		for (int i = 1; i <= n; i++) for (int l = 1, r = S[i].length(); r <= len; l++, r++) {
			int sub1 = ((hsh1[r] - 1ll * hsh1[l - 1] * pw1[r - l + 1]) % mod1 + mod1) % mod1, sub2 = ((hsh2[r] - 1ll * hsh2[l - 1] * pw2[r - l + 1]) % mod2 + mod2) % mod2;
			//if(sub1==hS1[i]&&sub2==hS2[i])cout<<"++"<<i<<' '<<l<<' '<<r<<'\n';
			ans += (
				sub1 == hS1[i] && sub2 == hS2[i]
				&& (pre1[l - 1] + 1ll * hT1[i] * pw1[len - r] + suf1[r + 1]) % mod1 == hY1
				&& (pre2[l - 1] + 1ll * hT2[i] * pw2[len - r] + suf2[r + 1]) % mod2 == hY2);
		}
		cout << ans << '\n';
	}
	return 0;
}

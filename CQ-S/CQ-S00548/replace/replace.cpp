#include <bits/stdc++.h>
using namespace std;
namespace WorldMachine {
typedef long long ll;
constexpr int N = 2e5 + 5, M = 5e6 + 5, S = 1 << 24, b = 131, p1 = 1e9 + 7, p2 = 1e9 + 9;
int n, q, len, tot, ch[M][26], fa[M], ed[M], pw1[M], pw2[M], H1[M], H2[M]; char s1[M], s2[M], s[M];
struct hashmap {
	int t, hd[S], nx[S], val[S]; ll key[S];
	void ins(ll x, int v) { int y = x & (S - 1); key[++t] = x, val[t] = v, nx[t] = hd[y], hd[y] = t; }
	int get(ll x) { int y = x & (S - 1), p = hd[y]; while (p && key[p] != x) p = nx[p]; return val[p]; }
} mp;
void main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q), pw1[0] = pw2[0] = 1;
	for (int i = 1; i < M; i++) pw1[i] = (ll)pw1[i - 1] * b % p1, pw2[i] = (ll)pw2[i - 1] * b % p2;
	for (int i = 1; i <= n; i++) {
		scanf("%s%s", s1, s2), len = strlen(s1);
		for (int j = 0; j < len; j++) s[j << 1] = s1[j];
		for (int j = 0; j < len; j++) s[j << 1 | 1] = s2[j];
		len <<= 1; int p = 0, h1 = 0, h2 = 0;
		for (int j = 0, o; j < len; j++) {
			h1 = ((ll)h1 * b + s[j]) % p1, h2 = ((ll)h2 * b + s[j]) % p2;
			if (!ch[p][o = s[j] - 'a']) fa[ch[p][o] = ++tot] = p, mp.ins((ll)h1 * p2 + h2, tot);
			p = ch[p][o];
		} ed[p]++;
	}
	for (int i = 1; i <= tot; i++) ed[i] += ed[fa[i]];
	while (q--) {
		scanf("%s%s", s1, s2), len = strlen(s1);
		if (len != (int)strlen(s2)) { puts("No"); continue; }
		for (int i = 0; i < len; i++) s[i << 1] = s1[i];
		for (int i = 0; i < len; i++) s[i << 1 | 1] = s2[i];
		len <<= 1; int mnd = -1, mxd = -1;
		for (int i = 0; i < len; i += 2) if (s[i] != s[i + 1]) mnd = mnd == -1 ? i : mnd, mxd = i + 1;
		int h1 = 0, h2 = 0, hh1 = 0, hh2 = 0; ll ans = 0, HH;
		for (int i = mnd + 1; i < len; i++) h1 = ((ll)h1 * b + s[i]) % p1, h2 = ((ll)h2 * b + s[i]) % p2;
		for (int i = mnd + 1; i < mxd; i++) hh1 = ((ll)hh1 * b + s[i]) % p1, hh2 = ((ll)hh2 * b + s[i]) % p2;
		H1[0] = H2[0] = 0;
		for (int i = 1; i <= len - mxd; i++) H1[i] = ((ll)H1[i - 1] * b + s[i + mxd - 1]) % p1, H2[i] = ((ll)H2[i - 1] * b + s[i + mxd - 1]) % p2;
		for (int i = mnd, p; ~i; i--) {
			h1 = (h1 + (ll)pw1[len - i - 1] * s[i]) % p1, h2 = (h2 + (ll)pw2[len - i - 1] * s[i]) % p2;
			hh1 = (hh1 + (ll)pw1[mxd - i - 1] * s[i]) % p1, hh2 = (hh2 + (ll)pw2[mxd - i - 1] * s[i]) % p2;
			if (i & 1) { continue; } HH = (ll)hh1 * p2 + hh2;
			p = mp.get(HH); if (!p) continue;
			int L = 0, R = len - mxd, mid, pt, fpt = 0, nh1, nh2;
			while (L <= R) {
				mid = (L + R) >> 1;
				nh1 = ((ll)hh1 * pw1[mid] + H1[mid]) % p1, nh2 = ((ll)hh2 * pw2[mid] + H2[mid]) % p2;
				if ((pt = mp.get((ll)nh1 * p2 + nh2))) fpt = pt, L = mid + 1; else R = mid - 1;
			} ans += ed[fpt] - ed[p];
		} cout << ans << '\n';
	}
}
}
int main() { return WorldMachine::main(), 0; }

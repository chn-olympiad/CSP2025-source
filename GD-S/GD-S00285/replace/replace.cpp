#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
#define csep constexpr
#define emp emplace
#define empb emplace_back
csep i32 inf32 = 0x3f3f3f3f;
csep i64 inf64 = 0x3f3f3f3f3f3f3f3fll;

// ---------------------------------------------------------------

// I'm in pain. Headache.

csep i32 HC = 2, b[] = {131, 137}, p[] = {1000000009, 993244853};
i32 bpow[HC][1000005], binv[HC][1000005];
using hv = array<i32, HC>;

i32 qpow(i32 x, i32 y, i32 mod) {
	i32 ret = 1;
	for (; y; y >>= 1, x = i64(x) * x % mod)
		if (y & 1)
			ret = i64(ret) * x % mod;
	return ret;
}
void preproc() {
	for (i32 k = 0; k < HC; ++k) {
		bpow[k][0] = binv[k][0] = 1;
		for (i32 i = 1; i < 1000005; ++i)
			bpow[k][i] = i64(bpow[k][i - 1]) * b[k] % p[k], binv[k][i] = qpow(bpow[k][i], p[k] - 2, p[k]);
	}
}

i32 n, q;
map<hv, multiset<hv>> rep;

hv hah(const string &s) {
	hv ret;
	for (i32 k = 0; k < HC; ++k) {
		ret[k] = 0;
		for (i32 i = 0; i < s.size(); ++i)
			ret[k] = (ret[k] + i64(bpow[k][i]) * (s[i] - 'a' + 1) % p[k]) % p[k];
	}
	return ret;
}
array<vector<i32>, HC> preh(const string &s) {
	array<vector<i32>, HC> ret;
	for (i32 k = 0; k < HC; ++k) {
		ret[k].assign(s.size(), 0);
		for (i32 i = 0; i < s.size(); ++i)
			ret[k][i] = ((i ? ret[k][i - 1] : 0) + i64(bpow[k][i]) * (s[i] - 'a' + 1) % p[k]) % p[k];
	}
	return ret;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	preproc();
	cin >> n >> q;
	for (i32 i = 1; i <= n; ++i) {
		string s, t;
		cin >> s >> t;
		rep[hah(s)].emp(hah(t));
	}
	while (q--) {
		string s, t;
		cin >> s >> t;
		if (s.size() != t.size()) {
			cout << "0\n";
			continue;
		}
		auto ps = preh(s), pt = preh(t);
		i32 ans = 0;
		for (i32 l = 0; l < s.size(); ++l) {
			for (i32 r = l; r < s.size(); ++r) {
				bool nma = 0;
				for (i32 k = 0; k < HC; ++k) {
					i32 sd = (ps[k].back() - (ps[k][r] - (l ? ps[k][l - 1] : 0) + p[k]) % p[k] + p[k]) % p[k];
					i32 td = (pt[k].back() - (pt[k][r] - (l ? pt[k][l - 1] : 0) + p[k]) % p[k] + p[k]) % p[k];
					if (sd != td)
						nma = 1;
				}
				if (nma)
					continue;
				hv fr, to;
				for (i32 k = 0; k < HC; ++k) {
					fr[k] = i64(binv[k][l]) * (ps[k][r] - (l ? ps[k][l - 1] : 0) + p[k]) % p[k];
					to[k] = i64(binv[k][l]) * (pt[k][r] - (l ? pt[k][l - 1] : 0) + p[k]) % p[k];
				}
				ans += rep[fr].count(to);
			}
		}
		cout << ans << '\n';
	}
	fflush(stdout);
	return 0;
}
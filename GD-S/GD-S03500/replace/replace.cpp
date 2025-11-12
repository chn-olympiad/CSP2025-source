#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define int ll

const int N = 200000 + 10;
const int inf = 1000000007;
using namespace std;

int read () {
	int x = 0, k = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') k = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x * k;
}


mt19937 Rnd(time(0));

namespace HshN {
	const int Nlen = 5000000 + 100, cNum = 128, Hlen = 2; int mxLen;
	#define int ll
	using aHsh = array<int, Hlen>; using Pai = pair<aHsh, int>;
	const aHsh mod = {998244353, 19260817};
	const aHsh bas = {131, 10007};
	aHsh cVal[cNum + 10]; long long ret[N]; map<aHsh, int> M; 

	inline int ksm (int x, int b, int p, int ret = 1) { for (; b; b >>= 1, x = x * x % p) if (b & 1) ret = ret * x % p; return ret; }
	inline int inv (int x, int p) { return ksm(x, p - 2, p); }

	void init () {
		for (int i = 0; i <= cNum; ++i)
			for (int k = 0; k < Hlen; ++k) cVal[i][k] = Rnd() % bas[k];
	}

	struct HshT {
		aHsh Hsh; int len;
		inline HshT (string s = "") {
			len = s.size(); for (int k = 0; k < Hlen; ++k) Hsh[k] = 0;
			for (int i = 0; i < len; ++i)
				for (int k = 0; k < Hlen; ++k)
					Hsh[k] = (Hsh[k] * bas[k] % mod[k] + s[i] + cVal[s[i]][k]) % mod[k];
		}
		
		inline HshT operator - (HshT B) {
			HshT ret; ret.len = len;
			for (int k = 0; k < Hlen; ++k) ret.Hsh[k] = ((Hsh[k] - B.Hsh[k]) % mod[k] + mod[k]) % mod[k];
			return ret;
		}

	};

	vector<aHsh> G[Nlen]; vector<Pai> Q[Nlen]; // 扫描线所需
 
 	void solve () {
 		for (int l = 1; l <= mxLen; ++l) {
			for (auto &V: G[l]) ++M[V];
			for (auto &P: Q[l]) {
				aHsh &V = P.first; int d = P.second;
				if (M.count(V)) ret[d] += M[V];
			}
		}
	}
 
	#undef int
}

int n, q;


signed main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0), n = read(), q = read(), HshN::init();
	for (int i = 1; i <= n; ++i) {
		string s1, s2; cin >> s1, cin >> s2; int len = s1.size(); HshN::mxLen = max(HshN::mxLen, len);
		HshN::G[len].push_back((HshN::HshT(s1) - HshN::HshT(s2)).Hsh); 
	}
	for (int _ = 1; _ <= q; ++_) {
		string s1, s2; cin >> s1, cin >> s2; int len1 = s1.size(), len2 = s2.size();
		if (len1 != len2) continue; /* len 不同，不关心 */ HshN::mxLen = max(HshN::mxLen, len1);
		HshN::HshT A = HshN::HshT(s1) - HshN::HshT(s2); int kl = len1; /* 末尾比对不同处 */
		while (--kl, s1[kl] == s2[kl]); HshN::aHsh dInv;
		for (int k = 0; k < HshN::Hlen; ++k) dInv[k] = HshN::inv(HshN::bas[k], HshN::mod[k]);
		for (int i = len1; i > kl; --i) {
			HshN::Pai Qry; Qry.first = A.Hsh, Qry.second = _; HshN::Q[i].push_back(Qry);
			for (int k = 0; k < HshN::Hlen; ++k) A.Hsh[k] = A.Hsh[k] * dInv[k] % HshN::mod[k];
		};
	}
	HshN::solve();
	for (int i = 1; i <= q; ++i) printf("%lld\n", HshN::ret[i]);
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

gebduyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrpavyxvtoobnaagrqnaqblorogkwljpaauytjbblfujxzjyeslmkgsrwhiwfdacprqrgofpanmgrhsitxppflpogfmgthoiovpqqxckapvgasnfepzcgkvtqfqyygcnjyhfpsapktq
gebdnhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdswavyxvtoobnaagrqnaqblorogkwljpaauytjbblfujxzjyeslmkgsrwhiwfdacprqrgofpanmgrhsitxppflpogfmgthoiovpqqxckapvgasnfepzcgkvtqfqyygcnjyhfpsapktq
*/


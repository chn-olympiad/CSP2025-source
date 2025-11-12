#include <bits/stdc++.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define MAX_N ((int) 2e5)
#define MAX_S ((int) 5e6)

int n, q;
std::string u[MAX_N], v[MAX_N];

std::string s, t;

namespace QL {
	const long long P0 = 37, P1 = 2129;
	const long long M0 = 998244353, M1 = 1'000'000'007;

	long long DEC0[MAX_S + 1], DEC1[MAX_S + 1];

	long long uh0[MAX_N], vh0[MAX_N], uh1[MAX_N], vh1[MAX_N];

	long long sh0[MAX_S], th0[MAX_S], sh1[MAX_S], th1[MAX_S];

	void init() {
		DEC0[0] = DEC1[0] = 1;
		for (int i = 1; i <= MAX_S; i++) DEC0[i] = DEC0[i - 1] * P0 % M0;
		for (int i = 1; i <= MAX_S; i++) DEC1[i] = DEC1[i - 1] * P1 % M1;

		for (int i = 0; i < n; i++) {
			uh0[i] = u[i][0] - 'a'; for (int j = 1; j < u[i].size(); j++) uh0[i] = (uh0[i] * P0 + u[i][j] - 'a') % M0;
			uh1[i] = u[i][0] - 'a'; for (int j = 1; j < u[i].size(); j++) uh1[i] = (uh1[i] * P1 + u[i][j] - 'a') % M1;
			vh0[i] = v[i][0] - 'a'; for (int j = 1; j < v[i].size(); j++) vh0[i] = (vh0[i] * P0 + v[i][j] - 'a') % M0;
			vh1[i] = v[i][0] - 'a'; for (int j = 1; j < v[i].size(); j++) vh1[i] = (vh1[i] * P1 + v[i][j] - 'a') % M1;
		}
	}

#define hashCode(h, dec, l, len, mod) (((h[(l) + (len)] - h[l] * dec[len]) % mod + mod) % mod)

	int query() {
		sh0[0] = s[0] - 'a'; for (int i = 1; i < s.size(); i++) sh0[i] = (sh0[i - 1] * P0 + s[i] - 'a') % M0;
		sh1[0] = s[0] - 'a'; for (int i = 1; i < s.size(); i++) sh1[i] = (sh1[i - 1] * P1 + s[i] - 'a') % M1;
		th0[0] = t[0] - 'a'; for (int i = 1; i < t.size(); i++) th0[i] = (th0[i - 1] * P0 + t[i] - 'a') % M0;
		th1[0] = t[0] - 'a'; for (int i = 1; i < t.size(); i++) th1[i] = (th1[i - 1] * P1 + t[i] - 'a') % M1;

		int l = -1, r = -1;
		for (int i = 0; i < s.size(); i++)
			if (s[i] ^ t[i]) l = ~l ? l : i, r = i;

		int ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = max(0, (signed) (l + u[i].size() - s.size())); j <= l && j + (r - l) < u[i].size(); j++)
				ret += (hashCode(sh0, DEC0, l - j - 1, u[i].size(), M0) == uh0[i] && hashCode(sh1, DEC1, l - j - 1, u[i].size(), M1) == uh1[i]
						&& hashCode(th0, DEC0, l - j - 1, u[i].size(), M0) == vh0[i] && hashCode(th1, DEC1, l - j - 1, u[i].size(), M1) == vh1[i]);

		return ret;
	}
}

main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	std::ios::sync_with_stdio(0);

	std::cin >> n >> q;
	for (int i = 0; i < n; i++) std::cin >> u[i] >> v[i];

	QL::init();

	while (q --> 0) {
		std::cin >> s >> t;
		printf("%d\n", QL::query());
	}

	return 0;
}

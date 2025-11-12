#include<bits/stdc++.h>

const int C = 2.5e6 + 7;
using ull = unsigned long long;
const ull basea = 211;
const int baseb = 321, mod = 998244353;

int n, q;
char s[C], t[C], p[C];
int plen;
std::map<std::pair<ull, int>, int> mp;
std::pair<ull, int> calc(int len) {
	int l = 0, r = 0;
	for (int i = 1; i <= len; ++i) {
		if (s[i] != t[i]) {
			if (l == 0)
				l = i;
			r = i;
		}
	}
	plen = 0;
	for (int i = 1; i < l; ++i)
		p[++plen] = s[i];
	p[++plen] = 'z' + 1;
	for (int i = r + 1; i <= len; ++i)
		p[++plen] = s[i];
	ull hash1 = 0;
	for (int i = l; i <= r; ++i)
		hash1 = (hash1 * basea + s[i]) * basea + t[i];
	long long hash2 = 0;
	for (int i = l; i <= r; ++i)
		hash2 = ((hash2 * baseb % mod + s[i]) * baseb % mod + t[i]) % mod;
	return std::make_pair(hash1, (int)hash2);
}
int ch[C][27], fail[C], cnt[C], trcnt;
void insert(int rt) {
	int u = rt;
	for (int i = 1; i <= plen; ++i) {
		if (!ch[u][p[i] - 'a'])
			ch[u][p[i] - 'a'] = ++trcnt;
		u = ch[u][p[i] - 'a'];
	}
	++cnt[u];
}
int qu[C], ql, qr;
void build(int rt) {
	ql = 1, qr = 0;
	for (int i = 0; i < 27; ++i) {
		if (ch[rt][i])
			qu[++qr] = ch[rt][i], fail[ch[rt][i]] = rt;
		else
			ch[rt][i] = rt;
	}
	while (ql <= qr) {
		int u = qu[ql++];
		cnt[u] += cnt[fail[u]];
		for (int i = 0; i < 27; ++i) {
			if (ch[u][i])
				fail[ch[u][i]] = ch[fail[u]][i], qu[++qr] = ch[u][i];
			else
				ch[u][i] = ch[fail[u]][i];
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s", s + 1, t + 1);
		int len = strlen(s + 1);
		std::pair<ull, int> hsh = calc(len);
		if (!mp[hsh])
			mp[hsh] = ++trcnt;
		insert(mp[hsh]);
//		p[plen + 1] = '\0';
//		printf("%s %s %s %d\n", s + 1, t + 1, p + 1, mp[hsh]);
		for (int j = 1; j <= len; ++j)
			s[i] = '\0', t[i] = '\0';
	}
	for (auto i : mp)
		if (i.second)
			build(i.second);
	for (int i = 1; i <= q; ++i) {
		scanf("%s%s", s + 1, t + 1);
		int slen = strlen(s + 1), tlen = strlen(t + 1);
		if (slen != tlen) {
			printf("0\n");
			for (int i = 1; i <= slen; ++i)
				s[i] = '\0';
			for (int i = 1; i <= tlen; ++i)
				t[i] = '\0';
			continue;
		}
		std::pair<ull, int> hsh = calc(slen);
		if (!mp.count(hsh)) {
			printf("0\n");
			for (int i = 1; i <= slen; ++i)
				s[i] = '\0';
			for (int i = 1; i <= tlen; ++i)
				t[i] = '\0';
			continue;
		}
//		p[plen + 1] = '\0';
//		printf("%s %s %s %d\n", s + 1, t + 1, p + 1, mp[hsh]);
		int u = mp[hsh], ans = 0;
		for (int i = 1; i <= plen; ++i) {
			u = ch[u][p[i] - 'a'];
			ans += cnt[u];
		}
		printf("%d\n", ans);
		for (int i = 1; i <= slen; ++i)
			s[i] = '\0';
		for (int i = 1; i <= tlen; ++i)
			t[i] = '\0';
	}
	return 0;
}

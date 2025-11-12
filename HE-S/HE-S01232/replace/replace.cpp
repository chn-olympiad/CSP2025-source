#include <bits/stdc++.h>
#define lep(i, a, b) for (int i = (a), ed##i = (b); i <= ed##i; ++i)
#define rep(i, a, b) for (int i = (a), ed##i = (b); i >= ed##i; --i)
#define pb push_back
#define fi first
#define se second

const int LN = 2e5 + 7;
const int LS = 5e6 + 7;
const int mod = 998244853;
const int bs = 19491001;
const int dl = 17;
typedef long long ll;

bool FISPOS;


int n, qy; std::string s1, s2, t1, t2;
int tot, fl[LS], ch[LS][26], tcn;
int cnt[LS << 2], ls[LS << 2], rs[LS << 2], rt[LS];
std::vector <int> o[LS], e[LS];
ll pw[LS], hs1[LS], hs2[LS];

bool ENDPOS;

#define md ((s + t) >> 1)
void mdy(int v, int&u, int d, int s = 0, int t = mod) {
	u = ++tcn; ls[u] = ls[v], rs[u] = rs[v], cnt[u] = cnt[v] + 1;
	if (s == t) return; d <= md ? mdy(ls[v], ls[u], d, s, md) : mdy(rs[v], rs[u], d, md + 1, t);
}
int qry(int p, int d, int s = 0, int t = mod) {
	if (!p) return 0; if (s == t) return cnt[p];
	return d <= md ? qry(ls[p], d, s, md) : qry(rs[p], d, md + 1, t);
}
#undef md
void sol(int u) {
	for (auto t : o[u]) mdy(rt[u], rt[u], t);
	for (int v : e[u]) rt[v] = rt[u], sol(v);
}
void ins() {
	ll hs = 0; int nw = 0, k, len = s1.size();
	lep(i, 0, len - 1) {
		hs = (hs * bs % mod + (s2[i] - s1[i]) * dl % mod) % mod, k = s1[i] - 'a';
		if (!ch[nw][k]) ch[nw][k] = ++tot; nw = ch[nw][k];
	} hs = (hs + mod) % mod;
	o[nw].pb(hs);
}
void bd() { std::queue <int> q;
	lep(k, 0, 25) if (ch[0][k]) q.push(ch[0][k]);
	while (!q.empty()) {
		int u = q.front(); q.pop(); e[fl[u]].pb(u);
		lep(k, 0, 25) {
			if (ch[u][k]) fl[ch[u][k]] = ch[fl[u]][k], q.push(ch[u][k]);
			else ch[u][k] = ch[fl[u]][k];
		}
	}
	sol(0);
}
ll qry() { ll ans = 0; int nw = 0, len = t1.size();
	if (t1.size() != t2.size()) return 0;
	t1 = " " + t1, t2 = " " + t2;
	lep(i, 1, len) hs1[i] = (hs1[i - 1] * bs % mod + t1[i] * dl % mod) % mod, 
		hs2[i] = (hs2[i - 1] * bs % mod + t2[i] * dl % mod) % mod;
	lep(i, 1, len) {
		nw = ch[nw][t1[i] - 'a'];
		if ((hs1[len] - hs1[i] * pw[len - i] % mod + mod) % mod == (hs2[len] - hs2[i] * pw[len - i] % mod + mod) % mod)
			ans += qry(rt[nw], (mod - hs1[i] + hs2[i]) % mod);
	}
	return ans;
}

int main() {
#ifndef DEBUG
	freopen("replace.in", "r", stdin);
	freopen("replace.out","w",stdout);
#endif
	std::ios::sync_with_stdio(false),
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int c1 = clock();
	
	pw[0] = 1;
	lep(i, 1, LS - 1) pw[i] = pw[i - 1] * bs % mod;
	std::cin >> n >> qy;
	lep(i, 1, n) std::cin >> s1 >> s2, ins();
	bd();
	while(qy--) std::cin >> t1 >> t2, std::cout << qry() << '\n';
	
	std::cerr << clock() - c1 << " ms " << std::fabs(&FISPOS - &ENDPOS) / 1024 / 1024 << " MB\n";
	return 0;
}

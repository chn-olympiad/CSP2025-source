#include <bits/stdc++.h>
#define ll int
#define LL long long
#define pir pair <ll, ll> 
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
const ll maxn = 2e5 + 10, M = 5e6 + 10, mod1 = 1e9 + 7, mod2 = 998244353, mod = 1;
template <class T1, class T2>
void chkmin(T1 &x, const T2 y) { x = x < y? x : y; }
template <class T1, class T2>
void chkmax(T1 &x, const T2 y) { x = x < y? y : x; }
template <class T1, class T2>
void add(T1 &x, const T2 y) { x = x + y >= mod? x + y - mod : x + y; }
template <class T1, class T2>
void sub(T1 &x, const T2 y) { x = x < y? x - y + mod : x - y; }
template <class T1, class T2>
void pls(const T1 x, const T2 y) { return x + y >= mod? x + y - mod : x + y; }
template <class T1, class T2>
void mus(const T1 x, const T2 y) { return x < y? x - y + mod : x - y; }
template <class T>
void rd(T &x) {
	char ch; ll f = 0;
	while(!isdigit(ch = getchar()))
		if(ch == '-') f = 1;
	x = ch - '0';
	while(isdigit(ch = getchar()))
		x = (x << 1) + (x << 3) + ch - '0';
	if(f) x = -x;
}
using namespace std;

ll n, q, ans[maxn], tot, cnt, trie[M][26];
ll l1[maxn], r1[maxn], l2[maxn], r2[maxn];
vector <char> a1[maxn], b1[maxn], a2[maxn], b2[maxn];
char a[M], b[M];
unordered_map <LL, ll> mp;
vector <ll> vec1[maxn], vec2[maxn];
ll hd1[M], nxt1[maxn], hd2[M], nxt2[maxn], bin[M], pos[maxn];

void dfs(ll p) {
	for(ll i = hd1[p]; i; i = nxt1[i]) {
		ll len = a1[i].size(), p = 2;
		for(ll j = r1[i] + 1; j < len; j++) {
			ll c = a1[i][j] - 'a';
			if(!trie[p][c]) trie[p][c] = ++cnt;
			p = trie[p][c];
		} ++bin[pos[i] = p];
	}
	for(ll i = hd2[p]; i; i = nxt2[i]) {
		ll len = a2[i].size(), p = 2;
		ans[i] = bin[2];
		for(ll j = r2[i] + 1; j < len; j++) {
			ll c = a2[i][j] - 'a';
			if(!trie[p][c]) trie[p][c] = ++cnt;
			ans[i] += bin[p = trie[p][c]];
		}
	}
	for(ll c = 0; c < 26; c++)
		if(trie[p][c]) dfs(trie[p][c]);
	for(ll i = hd1[p]; i; i = nxt1[i]) --bin[pos[i]];
}

void solve(ll k) {
	for(ll i = 1; i <= cnt; i++) {
		memset(trie[i], 0, sizeof trie[i]);
		hd1[i] = hd2[i] = 0;
	}
	cnt = 2;
	for(ll i: vec2[k]) {
		ll p = 1;
		for(ll j = l2[i] - 1; ~j; j--) {
			ll c = a2[i][j] - 'a';
			if(!trie[p][c])
				trie[p][c] = ++cnt;
			p = trie[p][c];
		}
		nxt2[i] = hd2[p], hd2[p] = i;
	}
	for(ll i: vec1[k]) {
		ll p = 1;
		for(ll j = l1[i] - 1; ~j; j--) {
			ll c = a1[i][j] - 'a';
			p = trie[p][c];
		}
		nxt1[i] = hd1[p], hd1[p] = i;
	}
	dfs(1);
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	rd(n), rd(q);
	for(ll i = 1; i <= n; i++) {
		scanf("%s%s", a, b);
		ll len = strlen(a);
		a1[i].resize(len), b1[i].resize(len);
		for(ll j = 0; j < len; j++) a1[i][j] = a[j], b1[i][j] = b[j];
		ll l = M + 1, r = -1;
		for(ll j = 0; j < len; j++)
			if(a1[i][j] != b1[i][j]) chkmin(l, j), chkmax(r, j);
		l1[i] = l, r1[i] = r;
		if(r == -1) continue;
		ll h1 = 0, h2 = 0;
		for(ll j = l; j <= r; j++) {
			h1 = (h1 * 131ll + a1[i][j]) %mod1;
			h2 = (h2 * 13331ll + a1[i][j]) %mod2;
			h1 = (h1 * 131ll + b1[i][j]) %mod1;
			h2 = (h2 * 13331ll + b1[i][j]) %mod2;
		}
		LL h = h1 * 1ll * mod2 + h2;
		if(!mp.count(h)) mp[h] = ++tot;
		vec1[mp[h]].pb(i);
	}
	for(ll i = 1; i <= q; i++) {
		scanf("%s%s", a, b);
		ll len = strlen(a);
		a2[i].resize(len), b2[i].resize(len);
		for(ll j = 0; j < len; j++) a2[i][j] = a[j], b2[i][j] = b[j];
		ll l = M + 1, r = -1;
		for(ll j = 0; j < len; j++)
			if(a2[i][j] != b2[i][j]) chkmin(l, j), chkmax(r, j);
		l2[i] = l, r2[i] = r;
		ll h1 = 0, h2 = 0;
		for(ll j = l; j <= r; j++) {
			h1 = (h1 * 131ll + a2[i][j]) %mod1;
			h2 = (h2 * 13331ll + a2[i][j]) %mod2;
			h1 = (h1 * 131ll + b2[i][j]) %mod1;
			h2 = (h2 * 13331ll + b2[i][j]) %mod2;
		}
		LL h = h1 * 1ll * mod2 + h2;
		if(mp.count(h)) vec2[mp[h]].pb(i);
	}
	for(ll i = 1; i <= tot; i++)
		if(!vec2[i].empty()) solve(i);
	for(ll i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}

#include <bits/stdc++.h>
#define ll int
#define LL long long
#define pir pair <ll, ll> 
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
const ll maxn = 1e4 + 20, mod = 1e9 + 7;
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

ll n, m, k, cnt, d[maxn], a[15], b[15][maxn], popcnt[32], siz[maxn];
LL ans = 1e18;
struct edge { ll u, v, w, t; } e[maxn * 7], E[maxn * 100], e1[32][maxn], e2[32][maxn];
bool cmp(edge a, edge b) { return a.w < b.w; }
ll find(ll x) { return d[x] ^ x? d[x] = find(d[x]) : x; }

void Sort(edge *L, edge *R) {
	if(L + 1 == R) return;
	edge *Mid = L + (R - L >> 1);
	Sort(L, Mid), Sort(Mid, R);
	static edge tmp[maxn * 100];
	edge *p = L, *q = Mid; ll c = 0;
	while(p != Mid || q != R) {
		if(p != Mid && (q == R || p -> w <= q -> w)) tmp[c++] = *p++;
		else tmp[c++] = *q++;
	}
	while(c) *--R = tmp[--c];
}

void mg(ll x, ll y) {
	if(siz[x] > siz[y]) d[y] = x, siz[x] += siz[y];
	else d[x] = y, siz[y] += siz[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n), rd(m), rd(k);
	for(ll i = 1; i <= m; i++)
		rd(E[i].u), rd(E[i].v), rd(E[i].w);
	Sort(E + 1, E + m + 1);
	for(ll i = 1; i <= n; i++) d[i] = i, siz[i] = 1;
	for(ll i = 1; i <= m; i++) {
		ll x = find(E[i].u), y = find(E[i].v);
		if(x == y) continue;
		mg(x, y), E[++cnt] = E[i];
	}
	for(ll i = 1; i <= k; i++) {
		rd(a[i]);
		for(ll j = 1; j <= n; j++) rd(b[i][j]);
	}
	for(ll S = 1; S < 32; S++) popcnt[S] = popcnt[S & (S - 1)] + 1;
	ll k1 = k / 2, k2 = k - k1;
	for(ll i = 1; i < n; i++) e[i] = E[i];
	for(ll i = 1; i <= k1; i++)
		for(ll j = 1; j <= n; j++)
			e[++cnt] = (edge) {n + i, j, b[i][j], i};
	Sort(e + 1, e + 1 + cnt);
	for(ll S = 0; S < (1 << k1); S++) {
		for(ll i = 1; i <= n + k; i++) d[i] = i, siz[i] = 1;
		ll tot = 0;
		for(ll i = 1; i <= cnt; i++) {
			if(e[i].t && !(S & (1 << e[i].t - 1))) continue;
			ll x = find(e[i].u), y = find(e[i].v);
			if(x ^ y) mg(x, y), e1[S][++tot] = e[i];
		}
	}
	cnt = 0;
	for(ll i = 1; i <= k2; i++)
		for(ll j = 1; j <= n; j++)
			e[++cnt] = (edge) {n + i + k1, j, b[i + k1][j], i};
	Sort(e + 1, e + 1 + cnt);
	for(ll S = 1; S < (1 << k2); S++) {
		for(ll i = 1; i <= n + k; i++) d[i] = i, siz[i] = 1;
		ll tot = 0;
		for(ll i = 1; i <= cnt; i++) {
			if(e[i].t && !(S & (1 << e[i].t - 1))) continue;
			ll x = find(e[i].u), y = find(e[i].v);
			if(x ^ y) mg(x, y), e2[S][++tot] = e[i];
		}
	}
	for(ll S = 0; S < (1 << k); S++) {
		for(ll i = 1; i <= n + k; i++) d[i] = i, siz[i] = 1;
		LL sum = 0, S1 = S & ((1 << k1) - 1), S2 = S >> k1;
		ll len1 = n - 1 + popcnt[S1], len2 = (S2? n - 1 + popcnt[S2] : 0);
		edge *E1 = e1[S1], *E2 = e2[S2];
		ll i = 1, j = 1;
		for(ll i = 1; i <= k; i++)
			if(S & (1 << i - 1)) sum += a[i];
		while(i <= len1 || j <= len2) {
			edge now;
			if(i <= len1 && (j > len2 || E1[i].w <= E2[j].w))
				now = E1[i++];
			else now = E2[j++];
			ll x = find(now.u), y = find(now.v);
			if(x ^ y) mg(x, y), sum += now.w;
		}
		chkmin(ans, sum);
	} printf("%lld\n", ans);
	return 0;
}

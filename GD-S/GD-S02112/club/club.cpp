#include <bits/stdc++.h>
#define ll int
#define LL long long
#define pir pair <ll, ll>
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
const ll maxn = 1e5 + 10, mod = 1e9 + 7;
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

ll T, n, a[maxn][3], b[maxn], cnt[3], w[maxn], len, ans;

void solve() {
	rd(n); cnt[0] = cnt[1] = cnt[2] = ans = len = 0;
	for(ll i = 1; i <= n; i++) {
		for(ll j = 0; j < 3; j++)
			rd(a[i][j]);
		b[i] = 0;
		for(ll j = 1; j < 3; j++)
			if(a[i][b[i]] < a[i][j]) b[i] = j;
		++cnt[b[i]], ans += a[i][b[i]];
	}
	if(max(max(cnt[0], cnt[1]), cnt[2]) * 2 > n) {
		for(ll i = 1; i <= n; i++)
			if(cnt[b[i]] * 2 > n) {
				ll t = 0;
				for(ll j = 0; j < 3; j++)
					if(j ^ b[i]) chkmax(t, a[i][j]);
				w[++len] = a[i][b[i]] - t;
			}
		sort(w + 1, w + 1 + len);
		ll k = max(max(cnt[0], cnt[1]), cnt[2]) - n / 2;
		for(ll i = 1; i <= k; i++) ans -= w[i];
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	rd(T); while(T--) solve();
	return 0;
}

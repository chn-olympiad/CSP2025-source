#include <bits/stdc++.h>
using namespace std;
#define ott(i,l,r) for (int i = (l); i <= (r); i ++)
#define tto(i,l,r) for (int i = (r); i >= (l); i --)
#define all(x) x.begin (), x.end ()
#define pb push_back
typedef long long ll;
const int N = 2e6 + 110;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
ll ans;
struct node {
	int a, b;
	ll c;
} e[N];
ll C[N];
int fa[N];
int find (int x) {
	return fa[x] ^ x ? fa[x] = find (fa[x]) : x;
}
void sol () {
	cin >> n >> m >> k;
	ott (i, 1, m) {
		cin >> e[i].a >> e[i].b >> e[i].c;
	}
	ott (j, 1, k) {
		cin >> C[j];
		ott (i, 1, n) {
			ll x;
			cin >> x;
			e[++ m] = {n + j, i, x};
		}
	}
	sort (e + 1, e + 1 + m, [&](node x, node y) {
		return x.c < y.c;
	});
	// ott (i, 1, m) cout << e[i].c << '\n';
	ans = INF;
	int sz = 1 << k;
	ott (s, 0, sz - 1) {
		int s = 0;
		ll sum = 0;
		ott (j, 1, k) if (s >> (j - 1) & 1) sum += C[j];
		ott (i, 1, n + k) fa[i] = i;
		ott (i, 1, m) {
			int a = find (e[i].a), b = find (e[i].b);
			// assert (max (e[i].a, e[i].b) <= n + k);
			ll x = e[i].c;
			// assert (e[i - 1].c <= e[i].c);
			if (e[i].a > n && !(s >> (e[i].a - n - 1) & 1)) continue;
			if (a ^ b) fa[a] = b, sum += x;
			if (sum > ans) break;
		}
		ans = min (ans, sum);
		// printf ("s = %d, sum = %lld\n", s, sum);
	}
	cout << ans << '\n';
	ans = 0;
}
int main () {
	freopen ("road.in", "r", stdin), freopen ("road.out", "w", stdout);
	int T = 1;
	while (T --) {
		sol ();
	}
	return 0;
}
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
int id[N];
struct node {
	int a, b;
	ll c;
} e[N];
ll C[13];
int fa[N];
int find (int x) {
	return fa[x] ^ x ? fa[x] = find (fa[x]) : x;
}
ll sol (int s) {
	ll sum = 0;
	int c = n, cc = 1;
	ott (j, 1, k) if (s >> (j - 1) & 1) sum += C[j], ++ c;
	ott (i, 1, n + k) fa[i] = i;
	ott (i, 1, m) {
		int a = find (e[i].a), b = find (e[i].b);
		ll x = e[i].c;
		if (e[i].a > n && !(s >> (e[i].a - n - 1) & 1)) continue;
		if (a ^ b) fa[a] = b, sum += x, ++ cc;
		if (cc == c) break;
	}
	return sum;
}
void sol () {
	int fl = 1;
	cin >> n >> m >> k;
	ott (i, 1, m) {
		cin >> e[i].a >> e[i].b >> e[i].c;
	}
	ott (j, 1, k) {
		cin >> C[j];
		fl &= (C[j] == 0);
		int lf = 0;
		ott (i, 1, n) {
			ll x;
			cin >> x;
			e[++ m] = {n + j, i, x};
			lf |= (x == 0);
		}
		fl &= lf;
	}
	sort (e + 1, e + 1 + m, [&](node x, node y) {
		return x.c < y.c;
	});
	int sz = 1 << k;
	ll lst = min (sol (0), sol (sz - 1));
	if (!fl) ott (s, 1, sz - 2) lst = min (lst, sol (s));
	cout << lst << '\n';
}
int main () {
	freopen ("road.in", "r", stdin), freopen ("road.out", "w", stdout);
	int T = 1;
	while (T --) {
		sol ();
	}
	return 0;
}
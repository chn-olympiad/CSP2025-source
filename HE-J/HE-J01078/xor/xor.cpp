#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll, ll > pii;

const int M = 5e5 + 10;
ll n, a[M], s[M], k, cnt, f[M];
map < ll, ll > ma;

struct node {
	ll l, r;
	bool operator < (const node & rhs) const {
		if (r == rhs.r) return l < rhs.l;
		return r < rhs.r;
	}
} p[M];

ll find(ll x, ll pos) {
	ll l = 1, r = pos - 1, ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (p[mid].r < x) {
			ans = mid;
			l = mid + 1;
		} else 
			r = mid - 1;
	}
	return ans;
}

int main() {
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		s[i] = (s[i - 1] ^ a[i]);
		ll w = (s[i] ^ k);
		ma[s[i - 1]] = i - 1;
		if (ma.find(w) == ma.end()) continue ;
		p[++ cnt] = node{ma[w] + 1, i};
	}
	sort(p + 1, p + 1 + cnt);
//	for (int i = 1; i <= cnt; i ++) 
//		cout << p[i].l << " " << p[i].r << "\n";
	
	for (int i = 1; i <= n; i ++) {
		ll lst = find(p[i].l, i);
		f[i] = max(f[i - 1], f[lst] + 1);
	}
	cout << f[cnt] << "\n";
	
	return 0;
}

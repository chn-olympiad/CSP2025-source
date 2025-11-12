#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e6 + 10;
const int B = 233, p = 1e9 + 7;

int n, Q, tot;
int h1[N], h2[N], b[N], L[N], R[N], hs[N], ht[N], Len[N];
char s[N], t[N];
map <int, int> mp;
vector <int> vec[N], q[N], h[N];

int hush (int l, int r) {
	return (h1[r]  + p - h1[l - 1] * b[r - l + 1] % p) % p;
}

int hush2 (int l, int r) {
	return (h2[r]  + p - h2[l - 1] * b[r - l + 1] % p) % p;
}

void work () {
	for (int i = 1; i <= n; ++i) {
		cin >> (s + 1) >> (t + 1);
		int x1 = 0, x2 = 0, len = strlen (s + 1);
		for (int j = 1; j <= len; ++j) {
			if (s[j] == 'b') x1 = j;
			if (t[j] == 'b') x2 = j;
		}
		L[i] = x1 - 1,  R[i] = len - x1;
		if (x1 > x2) q[x1 - x2].push_back (i);
		else h[x2 - x1].push_back (i);
	} 
	while (Q--) {
		cin >> (s + 1) >> (t + 1);	
		int ans = 0, x1 = 0, x2 = 0, len = strlen (s + 1);
		for (int j = 1; j <= len; ++j) {
			if (s[j] == 'b') x1 = j;
			if (t[j] == 'b') x2 = j;
		}
		if (x1 > x2) {
			for (int i = 0; i < q[x1 - x2].size(); ++i) {
				int id = q[x1 - x2][i];
				if (L[id] <= x1 - 1 && R[id] <= len - x1) ans++;
			}
		} else {
			for (int i = 0; i < h[x2 - x1].size(); ++i) {
				int id = h[x2 - x1][i];
				if (L[id] <= x1 - 1 && R[id] <= len - x1) ans++;
			}
		} cout << ans << '\n';
	}
}

signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> Q;
	if (n > 1000 && Q != 1) {
		work ();
		return 0;
	}
	b[0] = 1;
	for (int i = 1; i < N; ++i) b[i] = (b[i - 1] * B) % p;
	for (int i = 1; i <= n; ++i) {
		cin >> (s + 1) >> (t + 1);
		int len = strlen (s + 1), S = 0, T = 0;
		for (int j = 1; j <= len; ++j) S = (s[j] + S * B % p) % p;
		for (int j = 1; j <= len; ++j) T = (t[j] + T * B % p) % p;
		hs[i] = S, ht[i] = T, Len[i] = len;
	}
	while (Q--) {
		cin >> (s + 1) >> (t + 1);
		int len = strlen (s + 1), l = 1, r = n, ans = 0;
		for (int i = 1; i <= len; ++i) h1[i] = (s[i] + h1[i - 1] * B % p) % p;
		for (int i = 1; i <= len; ++i) h2[i] = (t[i] + h2[i - 1] * B % p) % p;
		while (l <= len && s[l] == t[l]) l++;
		while (r && s[r] == t[r]) r--;
		if (l == len + 1) {
			for (int i = 1; i <= n; ++i) if (hs[i] == ht[i]) ans++;
		} else {
			for (int i = 1; i <= n; ++i) 
				for (int hd = 1; hd <= len - Len[i] + 1; ++hd) {
					if (hd > l || hd + Len[i] - 1 < r) continue;
					int s1 = hush (hd, hd + Len[i] - 1), t1 = hush2 (hd, hd + Len[i] - 1);
					if (s1 == hs[i] && t1 == ht[i]) ans++;
				}
		} cout << ans << '\n';
	} return 0;
} 

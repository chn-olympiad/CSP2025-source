#define ffopen(s) \
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); \
if (*#s) freopen(#s ".in", "r", stdin); \
if (*#s) freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
using intl = long long;
const int N = 200000, L = 5000000;
const unsigned B = 31;
int n, q, len[N + 10];
unsigned a[N + 10], b[N + 10], bp[L + 10];
char s[N + 10], t[N + 10];
unsigned hs[L + 10], ht;
unsigned gtHa(char* s, unsigned* a) {
	int m = strlen(s);
	for (int i = 1; i <= m; i++) {
		a[i] = a[i - 1] * B + (s[i - 1] - 'a' + 1);
	} return a[m];
}
map<unsigned, int> st;
int query() {
	int m = 0, ans = 0;
	if ((m = strlen(s)) != (int) strlen(t)) return 0;
	st.clear();
	for (int i = 1; i <= m; i++) st[hs[i]] = i;
	for (int l = 1; l <= m; l++) {
		for (int j = 1; j <= n; j++) {
			unsigned Hsr = a[j] + hs[l - 1] * bp[len[j]];
			if (!st.count(Hsr)) continue;
			int r = st[Hsr];
			unsigned Hsn = hs[l - 1] * bp[m - l + 1] + b[j] * bp[m - r] + (hs[m] - hs[r] * bp[m - r]);
			if (Hsn == ht) ++ans;
		}
	}
	return ans;
}
void slove() {
	bp[0] = 1;
	for (int i = 1; i <= L; i++) bp[i] = bp[i - 1] * B;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s >> t;
		len[i] = strlen(s);
		a[i] = gtHa(s, hs);
		b[i] = gtHa(t, hs);
	}
	for (int i = 1; i <= q; i++) {
		cin >> s >> t;
		ht = gtHa(t, hs);
		gtHa(s, hs);
		cout << query() << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	slove();
	return 0;
}


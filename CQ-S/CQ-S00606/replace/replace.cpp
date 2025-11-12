#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;

constexpr int MAXN = 2e5, MAXM = 5e6, MAXK = 10, INF = 1e9; 

int n, m, M[MAXN+5], q, L, cnt, c[MAXN+5], len[MAXN+5], ans[MAXN+5];
string S[MAXN+5], T[MAXN+5];
bool B = true;
Pii p[MAXN+5];
unsigned long long pw[MAXM+5], H[2][MAXM+5];
vector<unsigned long long> h[2][MAXN+5];
map<Pii, int> mp;
struct node {
	string S, T;
	bool operator < (const node &T) const { return S.size() < T.S.size(); }
} a[MAXN+5];
struct Query {
	int fa, fb, val, id, opt;
	bool operator < (const Query &T) const { return val == T.val ? opt < T.opt : val < T.val; }
} Q[MAXN+5];

inline unsigned long long query(bool opt, int id, int l, int r) {
	if (l > r) return 0;
	return h[opt][id][r] - h[opt][id][l - 1] * pw[r - l + 1];
}
inline unsigned long long query(bool opt, int l, int r) {
	if (l > r) return 0;
	return H[opt][r] - H[opt][l - 1] * pw[r - l + 1];
}
inline bool check(string s) {
	int cnt = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] != 'a' && s[i] != 'b') return false;
		cnt += (s[i] == 'b');
	}
	return cnt == 1;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	IOS;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].S >> a[i].T;
		c[++L] = a[i].S.size();
		a[i].S = "#" + a[i].S, a[i].T = "#" + a[i].T;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		len[i] = a[i].S.size() - 1;
		h[0][i].emplace_back(0), h[1][i].emplace_back(0);
		for (int j = 1; j <= len[i]; ++j) {
			h[0][i].emplace_back(h[0][i][j - 1] * 131 + a[i].S[j]), h[1][i].emplace_back(h[1][i][j - 1] * 131 + a[i].T[j]);
		}
		B &= check(a[i].S), B &= check(a[i].T);
	}
	pw[0] = 1;
	for (int i = 1; i <= MAXM; ++i) pw[i] = pw[i - 1] * 131;
	sort(c + 1, c + 1 + L), L = unique(c + 1, c + 1 + L) - c - 1;
//	cout << "#" << L << '\n';
//	q = min(q, 1000);
	for (int cur = 1; cur <= q; ++cur) cin >> S[cur] >> T[cur], S[cur] = "#" + S[cur], T[cur] = "#" + T[cur], B &= check(S[cur]), B &= check(T[cur]);
	for (int cur = 1; cur <= q; ++cur) {
		if (S[cur].size() != T[cur].size()) { cout << "0\n"; continue; }
		m = S[cur].size();
		S[cur] = "#" + S[cur], T[cur] = "#" + T[cur];
		int l = 1, r = m;
		while (l <= m && S[cur][l] == T[cur][l]) ++l;
		while (r > 0 && S[cur][r] == T[cur][r]) --r;
		for (int i = 1; i <= m; ++i) {
			H[0][i] = H[0][i - 1] * 131 + S[cur][i];
			H[1][i] = H[1][i - 1] * 131 + T[cur][i];
		}
		if (l > r || c[L] < r - l + 1) { cout << "0\n"; continue; }
		int ans = 0;
		for (int i = n; i >= 1; --i) {
			if (len[i] < r - l + 1) break;
			for (int j = 1; j <= len[i] - r + l; ++j) {
				if (query(0, i, j, j + r - l) == query(0, l, r) && query(1, i, j, j + r - l) == query(1, l, r) && 
				j <= l && len[i] - (j + r - l) <= m - r &&
			 	query(0, i, 1, j - 1) == query(0, l - j + 1, l - 1) && query(0, i, j + r - l + 1, len[i]) == query(0, r + 1, len[i] + l - j) && 
				query(1, i, 1, j - 1) == query(1, l - j + 1, l - 1) && query(1, i, j + r - l + 1, len[i]) == query(1, r + 1, len[i] + l - j)) {
					++ans;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/

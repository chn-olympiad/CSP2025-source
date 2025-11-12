#include <bits/stdc++.h>

#define fir first
#define sec second

#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)

#define mkp make_pair
#define epb emplace_back
#define pb pop_back
#define sz(a) (int)(a.size())
#define All(a) begin(a), end(a)
#define mem(a, x) memset(a, x, sizeof(a))

using namespace std;

using ui = unsigned int;
using ll = long long;
using ull = unsigned long long;
using lll = __int128;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using vi = vector<int>;

template<typename T>
void chkmax(T &x, T y) {
	if (x < y) x = y;
}
template<typename T>
void chkmin(T &x, T y) {
	if (x > y) x = y;
}

const int kN = 2e5 + 10;
const int kL = 5e6 + kN * 2 + 10;

int n, q;

int tot_s;
string s[kN];

string t[kN];

int trie[kL][27], tot = 1;
int cnt[kL];
int fail[kL];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	L(i, 1, n) {
		string u, v;
		cin >> u >> v;
		if (u == v) continue;
		int cur1 = 0, cur2 = sz(u) - 1;
		while (u[cur1] == v[cur1]) ++cur1;
		while (u[cur2] == v[cur2]) --cur2;
		++tot_s;
		L(i, 0, cur1 - 1) s[tot_s] += u[i];
		s[tot_s] += (char)('z' + 1);
		L(i, cur1, cur2) s[tot_s] += u[i];
		L(i, cur1, cur2) s[tot_s] += v[i];
		s[tot_s] += (char)('z' + 1);
		L(i, cur2 + 1, sz(u) - 1) s[tot_s] += u[i];
		//cerr << s[tot_s] << '\n';
	}
	//cerr << "-----------\n";
	L(i, 1, q) {
		string u, v;
		cin >> u >> v;
		if (u == v) continue;
		int cur1 = 0, cur2 = sz(u) - 1;
		while (u[cur1] == v[cur1]) ++cur1;
		while (u[cur2] == v[cur2]) --cur2;
		L(j, 0, cur1 - 1) t[i] += u[j];
		t[i] += (char)('z' + 1);
		L(j, cur1, cur2) t[i] += u[j];
		L(j, cur1, cur2) t[i] += v[j];
		t[i] += (char)('z' + 1);
		L(j, cur2 + 1, sz(u) - 1) t[i] += u[j];
	}
	L(i, 1, tot_s) {
		int cur = 1;
		for (auto it : s[i]) {
			int ch = it - 'a';
			if (!trie[cur][ch]) trie[cur][ch] = ++tot;
			cur = trie[cur][ch];
		}
		++cnt[cur];
	}
	fail[1] = 0;
	queue<int> que;
	L(i, 0, 26) {
		if (trie[1][i]) {
			fail[trie[1][i]] = 1;
			que.emplace(trie[1][i]);
		} else {
			trie[1][i] = 1;
		}
	}
	while (!que.empty()) {
		int x = que.front(); que.pop();
		cnt[x] += cnt[fail[x]];
		L(i, 0, 26) {
			if (trie[x][i]) {
				fail[trie[x][i]] = trie[fail[x]][i];
				que.emplace(trie[x][i]);
			} else {
				trie[x][i] = trie[fail[x]][i];
			}
		}
	}
	L(i, 1, q) {
		int cur = 1;
		int ans = 0;
		for (auto it : t[i]) {
			int ch = it - 'a';
			cur = trie[cur][ch];
			ans += cnt[cur];
		}
		cout << ans << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define _for(i, a, b) for (int i = (a); i <= (int)(b); i ++ )

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PII;
const int N = 5e6 + 10, mod = 998244353, B1 = 131, B2 = 13331;
int n, q, cnt_id;
int ans[200010], ch[N][26];
struct Pi{
	string s1, s2;
	PII pos, lft;
	bool st;
}a[200010];
cc_hash_table<ULL, int> root, cnt;
vector<ULL> id[N];
vector<pair<ULL, int>> Qu[N];
ULL hsh[2][N], pw[2][N];

void insert(int idd, int pos, string s) {
	_for (i, 0, s.size() - 1) {
		int x = (s[i] - 'a');
		if (!ch[pos][x]) ch[pos][x] = ( ++ cnt_id);
		pos = ch[pos][x];
	}
	// cout << pos << ' ' << idd << ' ' << a[idd].lft.first << '\n';
	id[pos].push_back(a[idd].lft.first);
}

inline PII get_hash(int l, int r) {
	ULL hsh1 = hsh[0][r] - hsh[0][l - 1] * pw[0][r - l + 1];
	ULL hsh2 = (hsh[1][r] - hsh[1][l - 1] * pw[1][r - l + 1] % mod + mod) % mod;
	return {hsh1, hsh2};
}

void dfs(int u) {
	for (auto x : id[u]) {
		cnt[x] ++;
		// cout << "add " << x.first << ' ' << x.second << '\n';
	}
	for (auto x : Qu[u]) {
		ULL t = x.first;
		int idd = x.second;
		ans[idd] += cnt[t];
		// cout << "query " << idd << ' ' << t.first << ' ' << t.second << ' ' << cnt[t] << '\n';
	}
	_for (j, 0, 25)
		if (ch[u][j]) dfs(ch[u][j]);
	for (auto x : id[u]) {
		cnt[x] --;
		// cout << "sub " << x.first << '\n';
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pw[0][0] = pw[1][0] = 1;
	_for (i, 1, N - 1) 
		pw[0][i] = pw[0][i - 1] * B1, pw[1][i] = pw[1][i - 1] * B2 % mod;
	cin >> n >> q;
	vector<int> zlj;
	_for (i, 1, n) {
		cin >> a[i].s1 >> a[i].s2;
		a[i].st = (a[i].s1 == a[i].s2);
		if (!a[i].st) {
			ULL a1 = 0, a2 = 0;
			int id, lst = -1;
			_for (j, 0, a[i].s1.size() - 1) {
				if (a[i].s1[j] != a[i].s2[j]) {
					a1 = a1 * B1 + a[i].s1[j], a2 = (a2 * B2 + a[i].s2[j]) % mod;
					if (lst != -1) {
						a1 = a1 * B1 + (j - lst), a2 = (a2 * B2 + (j - lst)) % mod;
					}
					lst = j;
					id = j;
				}
			}
			ULL p1 = 0, p2 = 0;
			_for (j, 0, id) p1 = p1 * B1 + a[i].s1[j], p2 = (p2 * B2 + a[i].s1[j]) % mod;
			
			a[i].pos = {a1, a2}, a[i].lft = {p1, p2};
			 if (root.end() == root.find(a1)) {
			 	root[a1] = ++ cnt_id;
			 	zlj.push_back(cnt_id);
			 }
			insert(i, root[a1], a[i].s2.substr(id));
		}
	}
	_for (i, 1, q) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() != s2.size()) continue;
		s1 = " " + s1, s2 = " " + s2;
		ULL a1 = 0, a2 = 0;
		int id, lst = -1;
		_for (j, 0, s1.size() - 1) {
			if (s1[j] != s2[j]) {
				a1 = a1 * B1 + s1[j], a2 = (a2 * B2 + s2[j]) % mod;
				if (lst != -1) {
						a1 = a1 * B1 + (j - lst), a2 = (a2 * B2 + (j - lst)) % mod;
					}
					lst = j;
				id = j;
			}
		}
		if (root.end() == root.find(a1)) continue;
		int rt = root[a1];
	// 	cout << rt << '\n';
		_for (j, 1, id) {
			hsh[0][j] = hsh[0][j - 1] * B1 + s1[j], hsh[1][j] = (hsh[1][j - 1] * B2 + s1[j]) % mod;
		}
		_for (j, id, s1.size() - 1) {
			int x = (s2[j] - 'a');
			if (!ch[rt][x]) break;
			// cout << rt << ' ';
			rt = ch[rt][x];
		}
		_for (j, 1, id) {
			// cout << "::" << rt << ' ' << get_hash(j, id).first << ' ' << i << '\n';
			Qu[rt].push_back({get_hash(j, id).first, i});
		}
	}
	for (auto x : zlj) dfs(x);
	_for (i, 1, q) cout << ans[i] << '\n';
	return 0;
}

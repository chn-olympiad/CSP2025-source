#include <bits/stdc++.h>
using namespace std;

int n, q, pos[200005];
char s[5000005], t[5000005];
vector<int> S[200005], T;

namespace Trie {
	map<int, int> nxt[6000005]; int fa[6000005], rt[6000005], tot = 1, sm[6000005], tim[6000005], to;
	vector<int> f[6000005];
	void ins1(int x, vector<int> &vec, int p) {
		int now = 1, sz = (int)vec.size();
		for (int i = p; i < sz; i++) {
			if (!nxt[now][vec[i]]) nxt[now][vec[i]] = ++tot;
			fa[nxt[now][vec[i]]] = now, now = nxt[now][vec[i]];
		}
		f[now].push_back(x);
	}
	void ins2(int prv, int &now, vector<int> &vec, int p) {
		now = ++tot; nxt[now] = nxt[prv], sm[now] = sm[prv];
		if (!p) return sm[now]++, void();
		ins2(nxt[prv][vec[p]], nxt[now][vec[p]], vec, p - 1);
	}
	void build() {
		int tt = tot; rt[0] = tot + 1, tot++;
		for (int i = 1; i <= tt; i++) {
			for (int j = 0; j < (int)f[i].size(); j++) ins2(rt[(j == 0 ? tim[fa[i]] : to)], rt[to + 1], S[f[i][j]], pos[f[i][j]] - 1), ++to;
			tim[i] = (f[i].size() ? to : tim[fa[i]]);
		} rt[0] = 0;
	}
	int find(int r, vector<int> &T) {
		int now = r, sz = (int)T.size(), ans = sm[now];
		for (int i = 1; i < sz; i++) {
			if (nxt[now].find(T[i]) == nxt[now].end()) break;
			now = nxt[now][T[i]], ans += sm[now];
		}
		return ans;
	}
	int qry(vector<int> &T1, vector<int> &T2, int p) {
		int sz = (int)T2.size(), now = 1, ans = 0, flg = 1;
		for (int i = 1; i < sz; i++) {
			if (nxt[now].find(T2[i]) == nxt[now].end()) {
				if (i > p) ans += find(rt[tim[now]], T1);
				flg = 0; break;
			}
			if (i == p) ans -= find(rt[tim[now]], T1);
			now = nxt[now][T2[i]];
		}
		if (flg) ans += find(rt[tim[now]], T1);
		return ans;
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s %s", s + 1, t + 1); int sz = (int)strlen(s + 1), flg = 1;
		for (int j = 1; j <= sz; j++) flg &= (s[j] == t[j]);
		if (flg) i--, n--;
		else {
			S[i] = vector<int>(sz + 1);
			for (int j = 1; j <= sz; j++) {
				S[i][j] = (s[j] - 'a') * 26 + t[j] - 'a';
				if (s[j] != t[j] && !pos[i]) pos[i] = j;
			}
			Trie::ins1(i, S[i], pos[i]);
		}
	}
	Trie::build();
	for (int i = 1; i <= q; i++) {
		scanf("%s %s", s + 1, t + 1); int ps = 0, ls = 0, sz = (int)strlen(s + 1), sz2 = (int)strlen(t + 1);
		if (sz != sz2) { printf("0\n"); continue; }
		for (int j = 1; j <= sz; j++) {
			if (s[j] != t[j] && !ps) ps = j;
			if (s[j] != t[j]) ls = j;
		}
		vector<int> T1(ps), T2(sz - ps + 2);
		for (int j = ps - 1; j; j--) T1[ps - j] = (s[j] - 'a') * 26 + t[j] - 'a';
		for (int j = ps; j <= sz; j++) T2[j - ps + 1] = (s[j] - 'a') * 26 + t[j] - 'a';
		printf("%d\n", Trie::qry(T1, T2, ls - ps + 1));
	}
	return 0;
}

#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define fs first
#define sc second
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)
#define lc ls, l, mid
#define rc rs, mid + 1, r

using namespace std;
using pii = pair<int, int>;

const int maxn = 5e6 + 10;
const bool multidata = 0;

struct node {
	int ch[26] = {}, end, len, fail;
	node() = default;
};

int n, q;
int rt = 0, tot = 0;
node tr[maxn];
int fa[maxn][23];

void insert(string s) {
	int u = rt;
	for (char c : s) {
		if (!tr[u].ch[c - 'a']) tr[u].ch[c - 'a'] = ++tot, tr[tot].len = tr[u].len + 1;
		u = tr[u].ch[c - 'a'];
	}
	++tr[u].end;
}

void build() {
	queue<int> q;
	rep(i, 0, 25) if (tr[0].ch[i]) q.push(tr[0].ch[i]);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		rep(i, 0, 25) {
			if (tr[u].ch[i]) {
				tr[tr[u].ch[i]].fail = tr[tr[u].fail].ch[i];
				tr[tr[u].ch[i]].end += tr[tr[tr[u].fail].ch[i]].end;
				fa[tr[u].ch[i]][0] = tr[tr[u].fail].ch[i];
				rep(d, 1, 22) fa[tr[u].ch[i]][d] = fa[fa[tr[u].ch[i]][d - 1]][d - 1];
				q.push(tr[u].ch[i]);
			} else tr[u].ch[i] = tr[tr[u].fail].ch[i];
		}
	}
}

void fake_main() {
	cin >> n >> q;
	rep(i, 1, n) {
		string s, t, w;
		cin >> s >> t;
		rep(j, 0, (int) s.length() - 1) w += s[j], w += t[j];
		insert(w);
	}
	build();
	rep(i, 1, q) {
		string s, t, w;
		cin >> s >> t;
		rep(j, 0, (int) s.length() - 1) w += s[j], w += t[j];
		int l, r;
		for (int j = (int) w.length() - 2; j >= 0; j -= 2) {
			r = j + 1;
			if (w[j] != w[j + 1]) break;
		}
		for (int j = 0; j <= (int) w.length() - 2; j += 2) {
			l = j;
			if (w[j] != w[j + 1]) break;
		}
		int u = 0, ans = 0;
		rep(j, 0, (int) w.length() - 1) {
			u = tr[u].ch[w[j] - 'a'];
			if (j >= r && (j & 1)) {
				if (tr[u].len < j - l + 1) continue;
				ans += tr[u].end;
				int tmp = u;
				per(d, 22, 0) if (tr[fa[tmp][d]].len >= j - l + 1) tmp = fa[tmp][d];
				ans -= tr[fa[tmp][0]].end;
			}
		}
		cout << ans << endl;
	}
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	fake_main();
	return 0;
}
/*
这个匹配的左端点必须在某一个前缀内，后缀同理
 
*/

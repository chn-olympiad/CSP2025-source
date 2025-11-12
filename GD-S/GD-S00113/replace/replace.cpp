#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int n, q;
const int N = 2e5 + 5;
const int L = 5e6 + 5;
string a[N], b[N];
int flag = 0;
int e[L][26];
int c[L];
int cnt;

int chk(int x, int pos, string t1, string t2) {
	for (int i = 0; i < b[x].size(); i++) {
		t1[pos + i] = b[x][i];
	}
//	cout << t1 << ' ' << t2 << '\n';
	if (t1 == t2) return 1;
	else return 0;
}

void workA() {
	int now = 0;
	for (int i = 1; i <= n; i++) {
//		printf("##%d:\n", i);
		now = 0;
		for (int j = 0; j < a[i].size(); j++) {
			if (!e[now][a[i][j] - 'a']) {
				e[now][a[i][j] - 'a'] = ++cnt;
			}
			now = e[now][a[i][j] - 'a'];
//			printf("now=%d\n", now);
		}
		c[now] = i;
	}
	int ans = 0;
	while (q--) {
		ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			printf("0\n");
			continue;
		}
		for (int i = 0; i < t1.size(); i++) {
			now = 0;
			for (int j = i; j < t1.size(); j++) {
				if (!e[now][t1[j] - 'a']) break;
				now = e[now][t1[j] - 'a'];
				if (c[now]) {
//					printf("!!%d\n", now);
					ans += chk(c[now], i, t1, t2);
				}
			}
		}
		printf("%d\n", ans);
	}
}

map<int, vector<pii> > mp;
map<pii, int> tl;

int sch(int sft, int now, int x) {
	int l = now, r = tl[{sft, mp[sft][now].first}], ret = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (mp[sft][mid].second <= x) l = mid + 1, ret = mid;
		else r = mid - 1;
	}
	return ret;
}

void workB() {
	int sft, pa, pb;
	for (int i = 1; i <= n; i++) {
		pa = 0, pb = 0;
		for (int j = 0; j < a[i].size(); j++) {
			if (pa && pb) break;
			if (a[i][j] == 'b') pa = j;
			if (b[i][j] == 'b') pb = j;
		}
		sft = pb - pa;
		pii p;
		if (sft > 0) {
			p.first = pa;
			p.second = a[i].size() - 1 - pb;
		}
		else {
			p.first = pb;
			p.second = a[i].size() - 1 - pa;
		}
		mp[sft].push_back(p);
	}
	for (auto x : mp) {
		sort(x.second.begin(), x.second.end());
		x.second.push_back({1e9, 0});
		for (int i = 0; i < x.second.size() - 1; i++) {
			if (x.second[i].first != x.second[i + 1].first) {
				tl[{x.first, x.second[i].first}] = i;
			}
		}
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			printf("0\n");
			continue;
		}
		pa = 0, pb = 0;
		for (int j = 0; j < t1.size(); j++) {
			if (pa && pb) break;
			if (t1[j] == 'b') pa = j;
			if (t2[j] == 'b') pb = j;
		}
		sft = pb - pa;
		if (mp[sft].empty()) {
			printf("0\n");
			continue;
		}
		pii p;
		if (sft > 0) {
			p.first = pa;
			p.second = t1.size() - 1 - pb;
		}
		else {
			p.first = pb;
			p.second = t1.size() - 1 - pa;
		}
		int now = 0, ans = 0;
		while (mp[sft][now].first <= p.first) {
//			printf("%d ", now);
			if (mp[sft][now].second > p.second) {
				now = tl[{sft, mp[sft][now].first}] + 1;
				continue;
			}
			int nxt = sch(sft, now, p.second);
			ans += nxt - now + 1;
			now = tl[{sft, mp[sft][now].first}] + 1;
		}
		printf("%d\n", ans);
	}
}

void solve() {
	cin >> n >> q;
	if (q == 1 || (n <= 1e3 && q <= 1e3)) flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	if (flag) workA();
	else workB();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
	return 0;
}

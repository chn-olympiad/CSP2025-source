#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#define endl '\n'
using namespace std;
namespace IO {
	inline int Read() {
		int x = 0, k = 0; char ch = getchar();
		while (!isdigit(ch)) k |= (ch == '-'), ch = getchar();
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
		return k ? -x : x;
	}
}
const int MaxN = 2E5 + 10;
const int MaxL = 5E6 + 10;
int n, T, cnt1, cnt2;
int sum[MaxL];
string t1, t2;
string s[MaxN][3];
int tr1[30 * MaxN][26], tr2[30 * MaxN][26];
set<pair<int, int> > com1, com2;
vector<int> tag1[30 * MaxN], tag2[30 * MaxN];
void Insert1(string str, int id) {
	int u = 0;
	for (register int i = 0; i < str.size(); i++) {
		if (!tr1[u][str[i] - 'a']) tr1[u][str[i] - 'a'] = ++cnt1;
		u = tr1[u][str[i] - 'a'];
	}
	tag1[u].push_back(id);
}
void Search1(int pos) {
	int u = 0, p = pos;
	while (p < t1.size() && tr1[u][t1[p] - 'a']) {
		u = tr1[u][t1[p++] - 'a'];
		if (tag1[u].size() != 0) {
			for (register int i = 0; i < tag1[u].size(); i++) {
				com1.insert(make_pair(pos, tag1[u][i]));
			}
		}
	}
}
void Insert2(string str, int id) {
	int u = 0;
	for (register int i = 0; i < str.size(); i++) {
		if (!tr2[u][str[i] - 'a']) tr2[u][str[i] - 'a'] = ++cnt2;
		u = tr2[u][str[i] - 'a'];
	}
	tag2[u].push_back(id);
}
void Search2(int pos) {
	int u = 0, p = pos;
	while (p < t2.size() && tr2[u][t2[p] - 'a']) {
		u = tr2[u][t2[p++] - 'a'];
		if (tag2[u].size() != 0) {
			for (register int i = 0; i < tag2[u].size(); i++) {
				com2.insert(make_pair(pos, tag2[u][i]));
			}
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> T;
	for (register int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		Insert1(s[i][1], i);
		Insert2(s[i][2], i);
	}
	while (T--) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) { cout << 0 << endl; continue; }
		com1.clear();
		com2.clear();
		int len = t2.size() - 1;
		sum[len + 1] = 0;
		for (register int i = len; i >= 0; i--) sum[i] = sum[i + 1] + (t1[i] != t2[i]);
		for (register int i = 0; i <= len; i++) {
			Search1(i);
			Search2(i);
			if (t1[i] != t2[i]) break;
		}
		int ans = 0;
		for (set<pair<int, int> >::iterator it = com1.begin(); it != com1.end(); it++) {
			pair<int, int> x = *it;
			int r = x.first + s[x.second][1].size();
			if (!sum[r]) ans += com2.count(x);
		}
		cout << ans << endl;
	}
	return 0;
}


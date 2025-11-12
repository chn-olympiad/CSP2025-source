#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5;
constexpr int S = 1e7 + N + N;

int n, q;
//int syz[N + 1], fxj[N + 1];
//string bs1[N + 1], bs2[N + 1], bt1[N + 1], bt2[N + 1];
string s1[N + 1], s2[N + 1], t1[N + 1], t2[N + 1];
int cnt = 1, dfn, l[2][S + 2], r[2][S + 2], id_opt[2][N + 1], id_ask[2][N + 1];
struct Trie {
	int son[27];
	vector<int> vec[2];
	
	inline void clear() {
		vec[0].clear();
		vec[1].clear();
		for (int i = 0; i < 27; i++)
			son[i] = 0;
	}
} trie[S + 2];
int ccc, bit[S + 2], ans[N + 1];
vector<int> vecs[N + 1][2];

inline void modify(int num, int by) {
	for (int i = num; i <= S + 1; i += i & -i)
		bit[i] += by;
}

int query(int num) {
	int ret = 0;
	for (int i = num; i >= 1; i -= i & -i)
		ret += bit[i];
	return ret;
}

int insert(string str, int kd, int id) {
//	cerr << str << ' ' << kd << ' ' << id << '\n';
	int tmp = 1;
	for (char i : str) {
		if (!trie[tmp].son[i - 'a'])
			trie[trie[tmp].son[i - 'a'] = ++cnt].clear();
		tmp = trie[tmp].son[i - 'a'];
	}
	trie[tmp].vec[kd].push_back(id);
//	cerr << tmp << "***\n";
	return tmp;
}

inline void dfs(int node) {
//	cerr << node << ": " << trie[node].vec[0].size() << ' ' << trie[node].vec[1].size() << '\n';
	if (trie[node].vec[0].size() && trie[node].vec[1].size()) {
//		cerr << node << '\n';
		ccc++;
		vecs[ccc][0] = trie[node].vec[0];
		vecs[ccc][1] = trie[node].vec[1];
	}
	for (int i = 0; i < 27; i++)
		if (trie[node].son[i])
			dfs(trie[node].son[i]);
}

inline void get_info(int node, int l[S + 2], int r[S + 2]) {
	l[node] = ++dfn;
	for (int i = 0; i < 27; i++)
		if (trie[node].son[i])
			get_info(trie[node].son[i], l, r);
	r[node] = dfn;
}

inline void solve(vector<int> opt, vector<int> ask) {
	trie[cnt = 1].clear();
//	int v = syz[opt[0]];
	for (int i : opt) {
//		assert(syz[i] == v);
		id_opt[0][i] = insert(s1[i], 0, i);
	}
//	bool flag = false;
	for (int i : ask) {
//		assert(fxj[i] == v);
		id_ask[0][i] = insert(t1[i], 1, i);
//		if (i == 103)
//			flag = true;
	}
//	if (flag) {
//		cout << "opt:\n";
//		for (int i : opt)
//			cout << i << ": " << s1[i] << ' ' << s2[i] << '\n';
//		cout << "ask:\n";
//		for (int i : ask)
//			cout << i << ": " << t1[i] << ' ' << t2[i] << '\n';
//	}
	dfn = 0;
	get_info(1, l[0], r[0]);
	trie[cnt = 1].clear();
	for (int i : opt)
		id_opt[1][i] = insert(s2[i], 0, i);
	for (int i : ask) {
		id_ask[1][i] = insert(t2[i], 1, i);
//		if (i == 103)
//			cerr << i << ": " << t2[i] << ' ' << id_ask[1][i] << '\n';
	}
	dfn = 0;
	get_info(1, l[1], r[1]);
	vector<array<int, 3>> vec;
	for (int i : opt) {
		vec.push_back(array<int, 3>{l[0][id_opt[0][i]], l[1][id_opt[1][i]], -1});
		vec.push_back(array<int, 3>{1 + r[0][id_opt[0][i]], l[1][id_opt[1][i]], -2});
		vec.push_back(array<int, 3>{l[0][id_opt[0][i]], 1 + r[1][id_opt[1][i]], -2});
		vec.push_back(array<int, 3>{1 + r[0][id_opt[0][i]], 1 + r[1][id_opt[1][i]], -1});
	}
	for (int i : ask)
		vec.push_back(array<int, 3>{l[0][id_ask[0][i]], l[1][id_ask[1][i]], i});
	sort(vec.begin(), vec.end());
	for (auto [x, y, id] : vec) {
		if (id == -1)
			modify(y, 1);
		else if (id == -2)
			modify(y, -1);
		else {
//			if (id == 103)
//				cerr << "****" << y << '\n';
			ans[id] = query(y);
		}
	}
	for (auto [x, y, id] : vec) {
		if (id == -1)
			modify(y, -1);
		else if (id == -2)
			modify(y, 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
//		cerr << i << '\n';
		cin >> s1[i] >> s2[i];
//		bs1[i] = s1[i], bs2[i] = s2[i];
		if (s1[i] == s2[i])
			continue;
		string x = "", y = "";
		int id = 0;
		while (s1[i][id] == s2[i][id])
			id++;
		int di = s1[i].size() - 1;
		while (s1[i][di] == s2[i][di])
			di--;
		for (int j = id; j <= di; j++)
			x += s1[i][j], y += s2[i][j];
//		string tx = x, ty = y;
		string str = x + char('z' + 1) + y;
//		syz[i] = 
		insert(str, 0, i);
		x = y = "";
		for (int j = id - 1; j >= 0; j--)
			x += s1[i][j];
		for (int j = di + 1; j < s1[i].size(); j++)
			y += s1[i][j];
//		cerr << x << ' ' << tx << ' ' << y << '\n';
//		reverse(x.begin(), x.end());
//		assert(x + tx + y == s1[i]);
//		assert(x + ty + y == s2[i]);
//		reverse(x.begin(), x.end());
		s1[i] = x, s2[i] = y;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1[i] >> t2[i];
//		bt1[i] = t1[i], bt2[i] = t2[i];
		if (t1[i].size() != t2[i].size())
			continue;
		string x = "", y = "";
		int id = 0;
		while (t1[i][id] == t2[i][id])
			id++;
		int di = t1[i].size() - 1;
		while (t1[i][di] == t2[i][di])
			di--;
		for (int j = id; j <= di; j++)
			x += t1[i][j], y += t2[i][j];
		string str = x + char('z' + 1) + y;
//		fxj[i] = 
		insert(str, 1, i);
//		string tx = x, ty = y;
		x = y = "";
		for (int j = id - 1; j >= 0; j--)
			x += t1[i][j];
		for (int j = di + 1; j < t1[i].size(); j++)
			y += t1[i][j];
//		reverse(x.begin(), x.end());
//		assert(x + tx + y == t1[i]);
//		assert(x + ty + y == t2[i]);
//		reverse(x.begin(), x.end());
		t1[i] = x, t2[i] = y;
	}
//	cout << bs1[206] << ' ' << bs2[206] << ' ' << bt1[103] << ' ' << bt2[103] << '\n';
	dfs(1);
//	for (int i = 1; i <= n; i++)
//		cerr << s1[i] << ' ' << s2[i] << '\n';
//	for (int i = 1; i <= q; i++)
//		cerr << i << ": " << t1[i] << ' ' << t2[i] << '\n';
//	cerr << "---\n";
//	for (int i = 1; i <= ccc; i++) {
//		cerr << ":::\n";
//		for (int j : vecs[i][0])
//			cerr << j << ' ';
//		cerr << '\n';
//		for (int j : vecs[i][1])
//			cerr << j << ' ';
//		cerr << '\n';
//	}
	for (int i = 1; i <= ccc; i++)
		solve(vecs[i][0], vecs[i][1]);
	for (int i = 1; i <= q; i++)
		cout << ans[i] << '\n';
	return 0;
}
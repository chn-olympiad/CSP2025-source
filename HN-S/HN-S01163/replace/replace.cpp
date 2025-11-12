#include <iostream>
#include <map>

using namespace std;
using ull = unsigned long long;

const int MaxN = 2e5 + 10, MaxV = 5e6 + 10, B = 13331;

int nxt[MaxV][26], n, m, tot;
ull hs[2][MaxV], b[MaxV];
map<ull, int> edp[MaxV];
map<pair<pair<int, int>, pair<int, int>>, int> count;
string s1, s2;

ull hsh(string s, ull res = 0) {
	for (int i = 0; i < s.size(); i++) {
		res = res * B + s[i];
	}
	return res;
}

void insert(string s, ull num, int p = 0) {
	for (int i = 0; i < s.size(); i++) {
		int c  = s[i] - 'a';
		if (!nxt[p][c]) nxt[p][c] = ++tot;
		p = nxt[p][c];
	}
	edp[p][num]++;
}

ull get(ull hs[MaxN], int l, int r) {
	if (l > r) return 0; 
	return hs[r] - hs[l - 1] * b[r - l + 1];
}

int query(string s, int id, int p = 0, int res = 0) {
	for (int i = id; i < s.size(); i++) {
		int c = s[i] - 'a';
		if (!nxt[p][c]) return res;
		p = nxt[p][c];
		if (get(hs[0], i + 1, s.size() - 1) == get(hs[1], i + 1, s.size() - 1) && edp[p].count(get(hs[1], id, i))) res += edp[p][get(hs[1], id, i)];
	}
	return res;
}

pair<int, int> Count(string s, int p = 0) {
	pair<int, int> res;
	for (int i = p; i < s1.size(); i++) {
		if (s1[i] == 'a') {
			res.first++;
		} else if (s1[i] == 'b') {
			res.second = i;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	b[0] = 1;
	for (int i = 1; i < MaxV; i++) {
		b[i] = b[i - 1] * B;
	}
	cin >> n >> m;
	bool flagg = 1;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		insert(s1, hsh(s2));
	}
	for (int i = 1; i <= m; i++) {
		cin >> s1 >> s2;
		s1 = " " + s1, s2 = " " + s2;
		for (int i = 1; i < s1.size(); i++) {
			hs[0][i] = hs[0][i - 1] * B + s1[i];
		}
		for (int i = 1; i < s2.size(); i++) {
			hs[1][i] = hs[1][i - 1] * B + s2[i];
		}
		int ans = 0;
		for (int i = 1; i < s1.size(); i++) {
			if (hs[0][i - 1] == hs[1][i - 1]) { // 后面进行替换
				ans += query(s1, i);
			} else {
				break; // 前面都不同后面怎么换都无效 
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

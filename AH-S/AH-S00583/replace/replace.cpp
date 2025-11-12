#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<utility>
using namespace std;
int n, q;
string s1[200005], s2[200005], u, v;
struct Node{
	string Left, Mid, Right;
	int cnt;
};
map<string, vector<Node> > chg;
int Mxsiz;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		Mxsiz = max(Mxsiz, (int)s1[i].size());
		int l = 0, r = 0;
		bool lc = 0;
		for (int j = 0; j < (int)s1[i].size(); j++)
			if (s1[i][j] != s2[i][j]) r = j, l = (lc == 0 ? j : l), lc = 1;
		vector<Node> TMP = chg[s1[i].substr(l, r - l + 1)];
		Node It_ = {s2[i].substr(0, l), s2[i].substr(l, r - l + 1), s2[i].substr(r + 1, ((int)s1[i].size()) - r - 1), 1};
		bool ned = 1;
		for (int j = 0; j < (int)TMP.size(); j++) {
			Node T = TMP[j];
			if (It_.Left == T.Left && It_.Mid == T.Mid && It_.Right == T.Right) {
				ned = 0;
				++TMP[j].cnt;
				break;
			}
		}
		if (ned) TMP.push_back(It_);
		chg[s1[i].substr(l, r - l + 1)] = TMP;
	}
	while (q--) {
		cin >> u >> v;
		int l = 0, r = 0;
		bool lc = 0;
		for (int i = 0; i < (int)u.size(); i++)
			if (u[i] != v[i]) r = i, l = (lc == 0 ? i : l), lc = 1;
		string U = u.substr(l, r - l + 1), V = v.substr(l, r - l + 1);
		string L = u.substr(0, l);
		string R = u.substr(r + 1, ((int)u.size()) - r - 1);
		long long Ans = 0;
		vector<Node> TMP = chg[U];
		if (TMP.size()) {
			for (int j = 0; j < (int)TMP.size(); j++) {
				Node T = TMP[j];
				if ((int)T.Left.size() <= (int)L.size() && (int)T.Right.size() <= (int)R.size() && T.Mid == V)
				if ((T.Left == L.substr(((int)L.size()) - ((int)T.Left.size()), (int)T.Left.size()) || L.size() == 0) && T.Mid == V && (T.Right == R.substr(0, (int)T.Right.size()) || R.size() == 0))
					Ans += T.cnt;
			}
		} else {
			chg.erase(U);
		}
		cout << Ans << '\n';
	}
	return 0;
}
//               一路走好
//             王狗灏、来中杨
//              ^   ^   ^
//                & & &
//                | | |
//                \ | /
//                 |||
//                 |||
//                 |||
//            -------------
//T3, pian fen
//AC!!!!!!100pts

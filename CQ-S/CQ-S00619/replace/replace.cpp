#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int LEN = 5e6 + 5;
const int N = 2e5 + 5;
struct change{
	string from, to;
	int cha, l, r, pos1, pos2;
}turn[N];
int n, q;
struct query {
	string s, t;
	int cha, l, r, pos1, pos2;
}Q[N];
map<int, vector<change>> mp;
int L1, L2;
bool pre[LEN], suf[LEN];
vector<int> KMP(string s) {
	int n = s.size();
	vector<int> pi(n);
	pi[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[j] != s[i]) j = pi[j - 1];
		pi[i] = j;
		if (s[i] == s[j]) 
			pi[i] ++;
	}
	return pi;
}
void solve1() {
	for (int test = 1; test <= q; ++ test) {
		long long ans = 0;
		pre[0] = true;
		for (int i = 1; i <= Q[test].s.size(); ++i) 
			pre[i] = pre[i - 1] & (Q[test].s[i - 1] == Q[test].t[i - 1]);
		suf[Q[test].s.size()] = true;
		for (int i = Q[test].s.size() - 1; i >= 0; --i)
			suf[i] = (suf[i + 1] & (Q[test].s[i] == Q[test].t[i]));
		for (int i = 1; i <= n; ++i) {
			string cut1 = turn[i].from + "#" + Q[test].s;
			string cut2 = turn[i].to + "#" + Q[test].t;
//			cout << cut1 << ' ' << cut2 << '\n';
			auto vec1 = KMP(cut1);
			auto vec2 = KMP(cut2);
			bool flag = true;
			for (int j = turn[i].from.size(); j < vec1.size(); ++j) {
//				cout << j << '\n';
//				cout << boolalpha << suf[j - turn[i].from.size()] << '\n';
				if (pre[j - turn[i].from.size() * 2] && vec1[j] == turn[i].from.size() && vec2[j] == turn[i].from.size() && suf[j - turn[i].from.size()]) {
					++ans;
				}
			}
		}
		cout << ans << '\n';
	}
}
void Sub() {
	for (int tst = 1; tst <= q; ++tst) {
		for (int j = 0; j < Q[tst].s.size(); ++j) {
			if (Q[tst].s[j] == 'b') {
				Q[tst].pos1 = j;
				break;
			}
		}
		for (int j = 0; j < Q[tst].s.size(); ++j) {
			if (Q[tst].s[j] == 'b') {
				Q[tst].pos1 = j;
				break;
			}
		}
	}
}
int main() {
	FASTIO;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> turn[i].from >> turn[i].to;
		L1 += (turn[i].from.size() + turn[i].to.size());
	}
	for (int i = 1; i <= q; ++i) {
		cin >> Q[i].s >> Q[i].t;
		L2 += (Q[i].s.size() + Q[i].t.size());
	}
	if (L1 <= 200 && L2 <= 200) {
		solve1();
		// 10 pts
		return 0;
	}
	if (q == 1 && n <= 1000) {
		solve1();
		// 5 pts
		return 0;
	}
	solve1();
	return 0;
}
// 15pts

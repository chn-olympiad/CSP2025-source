#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 5e6 + 7;

vector<int> nxt[N];

string s1[N], s2[N];
int len[N];

void get(int id) {
	nxt[id].resize(len[id] + 5);
	int j = 0;
	rep(i, 2, len[id]) {
		while(j && s1[id][j + 1] != s1[id][i]) j = nxt[id][j];
		if(s1[id][j + 1] == s1[id][i]) ++j;
		nxt[id][i] = j;
	}
}

int main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q, ans = 0;
	cin >> n >> q;
	rep(i, 1, n) cin >> s1[i] >> s2[i], get(i), len[i] = s1[i].size(), s1[i] = " " + s1[i], s2[i] = " " + s2[i];
	while(q--) {
		ans = 0;
		string s, t;
		int l, r;
		cin >> s >> t;
		int len1 = s.size(), len2 = t.size();
		if(len1 != len2) {
			cout << 0 << endl;
			continue;
		}
		s = " " + s, t = " " + t;
		rep(id, 1, n) {
			int j = 0;
			rep(i, 1, len1) {
				while(j && s1[id][j + 1] != s[i]) j = nxt[id][j];
				if(s1[id][j + 1] == s[i]) ++j;
				if(j == len[id]) {
					int lst = i - len[id] + 1;
					string pre = s;
					rep(w, lst, i) s[w] = s2[id][w - lst + 1];
					if(s == t) ++ans;
					s = pre;
					j = nxt[id][j];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

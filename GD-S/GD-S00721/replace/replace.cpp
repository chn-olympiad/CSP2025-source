#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define mp make_pair
#define fi first
#define se second
#define db double
#define pii pair < int, int >

const int MAXN = 2e5 + 7;

const ull Base = 1e9 + 7;

int n, q;

string S1[MAXN], S2[MAXN];
ull H1[MAXN], H2[MAXN], Pre[MAXN];

ull get(string s) {
	ull sum = 0;
	for (int i = 0; i < s.size(); i ++) sum = (sum * Base + s[i]);
	return sum;
}

string s1, s2; ull h1, h2;

int Nxt[MAXN][30], sum;

void Work(int id, int l, int r) {
	if (r - l + 1 < S1[id].size()) return ;
	int nxt = -1;
	for (int i = l; i <= r; i ++) if (s1[i] == S1[id][0]) { nxt = i; break; }
	if (nxt == -1) return ;
	if (h1 - H1[id] * Pre[s1.size() - nxt - S1[id].size()] + H2[id] * Pre[s1.size() - nxt - S1[id].size()] == h2) sum ++;
	Work(id, nxt + 1, r);
	return ;
}

void Solve() {
	cin >> s1 >> s2; h1 = get(s1), h2 = get(s2);
 	sum = 0;
 	for (int i = 1; i <= n; i ++) Work(i, 0, s1.size() - 1);
	cout << sum << '\n';
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	if (n > 100) {
		Pre[0] = 1;
		for (int i = 1; i <= MAXN - 7; i ++) Pre[i] = Pre[i - 1] * Base;
		cin >> n >> q;
		for (int i = 1; i <= n; i ++) {
			cin >> S1[i] >> S2[i];
			H1[i] = get(S1[i]), H2[i] = get(S2[i]);
		}
		while (q --) Solve();
	}
	else {
	for (int i = 1; i <= n; i ++) cin >> S1[i] >> S2[i];
	while (q --) {
		string s1, s2; cin >> s1 >> s2;
		int ans = 0;
		for (int i = 0; i < s1.size(); i ++)
			for (int j = 1; j <= n; j ++) {
				if (i + S1[j].size() > s1.size()) continue; 
				if (s1[i] == S1[j][0]) {
					int cnt = 0;
					for (int k = i; k < i + S1[j].size(); k ++) if (s1[k] != S1[j][k - i]) { cnt = 1; break; }
					if (cnt) continue;
					string news;
					for (int k = 0; k < i; k ++) news = news + s1[k];
					news += S2[j];
					for (int k = i + S2[j].size(); k < s1.size(); k ++) news += s1[k];
					if (news == s2) ans ++;
				}
			}
		cout << ans << '\n';
	}
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/

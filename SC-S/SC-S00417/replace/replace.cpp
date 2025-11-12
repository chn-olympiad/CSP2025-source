#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int p = 43;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
int n, m, l1, l2;
string s1[maxn], s2[maxn], t1[maxn], t2[maxn];
LL h(string &c) {
	int len = c.size() - 1;
	LL res = 0;
	for (int i = 1; i <= len; i++)
		res = res * p + (c[i] - 'a' + 1);
	return res;
}
int find(string &c) {
	int len = c.size() - 1;
	for (int i = 1; i <= len; i++)
		if (c[i] == 'b')
			return i;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		l1 += (s1[i].size() + s2[i].size());
		s1[i] = ' ' + s1[i];
		s2[i] = ' ' + s2[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> t1[i] >> t2[i];
		l1 += (t1[i].size() + t2[i].size());
		t1[i] = ' ' + t1[i];
		t2[i] = ' ' + t2[i];
	}
	if (l1 <= 2000 && l2 <= 2000) {
		unordered_map<LL, unordered_map<LL, int > > Map;
		for (int i = 1; i <= n; i++)
			Map[h(s1[i])][h(s2[i])]++;
		for (int i = 1; i <= m; i++) {
			int L = 1, R = t1[i].size() - 1;
			while (t1[i][L] == t2[i][L]) L++;
			while (t1[i][R] == t2[i][R]) R--;
			LL ans = 0;
			for (int l = 1; l < (int)t1[i].size(); l++) {
				LL h1 = 0, h2 = 0;
				for (int r = l; r < (int)t1[i].size(); r++) {
					h1 = h1*p + (t1[i][r] - 'a' + 1);
					h2 = h2*p + (t2[i][r] - 'a' + 1);
					if (l <= L && R <= r)
						ans += Map[h1][h2];
				}
			}
			cout << ans << '\n';
		}
	} else {
		for (int i = 1; i <= m; i++) {
			int A = find(t1[i]), B = find(t2[i]);
			int L = min(A, B), R = t1[i].size() - max(A, B);
			LL ans = 0;
			for (int i = 1; i <= n; i++) {
				int a = find(s1[i]), b = find(s2[i]);
				int l = min(a, b), r = s1[i].size() - max(a, b);
				if ((A - B) == (a - b) && l <= L && r <= R)
					ans++;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
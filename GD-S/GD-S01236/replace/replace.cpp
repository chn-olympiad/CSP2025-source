/*

正解貌似是 AC自动机？
没学 QwQ 

*/
#include <bits/stdc++.h>
 
using namespace std;
using cint = const int;
using LL = long long;
using cLL = const long long;
using uLL = unsigned long long;

#define N 200005
#define L 5000005
#define base 31
#define mod 998244353
#define inf 1000000007

const double eps = 1e-9;
const double PI = acos(-1.0);

uLL hsh[N][2];
uLL pw[L];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	pw[0] = 1;
	for (int i = 1; i < L; ++i)
		pw[i] = pw[i - 1] * base;
	int n, q;
	scanf("%d%d", &n, &q);
	map<pair<int, int>, int> cnt;
	for (int i = 1; i <= n; ++i) {
		static char s[L];
		scanf("%s", s + 1);
		cint len = strlen(s + 1);
		for (int j = 1; j <= len; ++j)
			hsh[i][0] = hsh[i][0] * base + s[j] - 'a' + 1;
		scanf("%s", s + 1);
		for (int j = 1; j <= len; ++j)
			hsh[i][1] = hsh[i][1] * base + s[j] - 'a' + 1;
		++cnt[make_pair(hsh[i][0], hsh[i][1])];
	}
	for (static uLL t[2][L]; q--; ) {
		t[0][0] = t[1][0] = 0ull;
		static char s[L];
		scanf("%s", s + 1);
		cint len = strlen(s + 1);
		for (int i = 1; i <= len; ++i)
			t[0][i] = t[0][i - 1] * base + s[i] - 'a' + 1;
		scanf("%s", s + 1);
		for (int i = 1; i <= len; ++i)
			t[1][i] = t[1][i - 1] * base + s[i] - 'a' + 1;
		auto get_hash = [](const uLL *hsh, cint l, cint r) -> uLL {
			return hsh[r] - hsh[l - 1] * pw[r - l + 1];
		};
		//
		int l = 0, r = len + 1;
		for (; l < len && t[0][l + 1] == t[1][l + 1]; ++l);
		for (; r >= 2 && get_hash(t[0], r - 1, len) == get_hash(t[1], r - 1, len); --r);
		int ans = 0;
		for (int i = 1; i <= l + 1; ++i) {
			for (int j = r - 1; j <= len; ++j) {
				ans += cnt[make_pair(get_hash(t[0], i, j), get_hash(t[1], i, j))];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

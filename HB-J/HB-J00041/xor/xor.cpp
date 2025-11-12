#include <bits/stdc++.h>
#define fori(na, st, ed) for (int na = st; na <= ed; ++na)
#define forn(na, ed) fori(na, 1, ed)
#define fora(na, st, ed) for (int na = st; na >= ed; --na)
#define fors(na, st) fora(na, st, 1)
#ifdef __linux__
#define ffgetc getchar_unlocked
#define ffputc putchar_unlocked
#else
#define ffgetc getchar
#define ffputc putchar
#endif
using namespace std;
typedef pair<int, int> pii;
template <typename Tp> void read(Tp &x) {
	x = 0;
	char ch = 0;
	int f = 1;
	while (ch < '0' || ch > '9') {
		ch = ffgetc();
		if (ch == '-') {
			f = -1;
		}
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ffgetc();
	}
	x *= f;
}
template <typename T1, typename... T2> void read(T1 &x, T2 &...y) {
	read(x);
	read(y...);
}
const int N = 5e5 + 5;
int n, ans;
long long k, a[N], dp[N], s[N];
bool bk[N];
unordered_map<long long, vector<pii>> mp;
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	read(n, k);
	forn(i, n) {
		read(a[i]);
		s[i] = s[i - 1] ^ a[i];
		forn(j, i) { mp[s[i] ^ s[j - 1]].emplace_back(j, i); }
	}
	auto t = mp[k];
	sort(t.begin(), t.end(), [](const pii &x, const pii &y) -> bool {
		return x.second - x.first == y.second - y.first
				   ? x.first < y.first
				   : x.second - x.first < y.second - y.first;
	});
	int cnt = 0;
	for (auto y : t) {
		bool f = 0;
		fori(i, y.first, y.second) {
			if (bk[i]) {
				f = 1;
				break;
			}
		}
		if (!f) {
			cnt++;
			fori(i, y.first, y.second) { bk[i] = 1; }
		}
	}
	cout << cnt;
	return 0;
}
// QwQQwQQwQ
// feropen("xor.in", "w", stdout);
// feropen("xor.ans", "r", stdin);
// QwQQwQQwQ
// #Shang4Shan3Ruo6Shui4

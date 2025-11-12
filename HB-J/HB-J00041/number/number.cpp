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
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int n, m;
string s;
vector<int> v;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (auto c : s) {
		if (isdigit(c)) {
			v.push_back(c - '0');
		}
	}
	sort(v.begin(), v.end(), [](const int &x, const int &y) { return x > y; });
	for (auto i : v) {
		cout << i;
	}
	return 0;
}
// QwQQwQQwQ
// feropen("numbers.in", "w", stdout);
// feropen("numbers.ans", "r", stdin);
// QwQQwQQwQ
// #Shang4Shan3Ruo6Shui4

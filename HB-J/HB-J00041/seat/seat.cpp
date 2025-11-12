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
const int N = 1e3 + 5;
int n, m;
pair<int, int> a[N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	forn(i, n * m) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n * m + 1,
		 [](const pair<int, int> &x, const pair<int, int> &y) {
			 return x.first > y.first;
		 });
	int x = 1, y = 1, id = 1;
	if (a[1].second == 1) {
		cout << "1 1";
		return 0;
	}
	forn(i, n * m) {
		do {
			id++;
			x++;
			if (a[id].second == 1) {
				cout << y << " " << x;
				return 0;
			}
		} while (x < n);
		y++;
		id++;
		if (a[id].second == 1) {
			cout << y << " " << x;
			return 0;
		}
		do {
			x--;
			id++;
			if (a[id].second == 1) {
				cout << y << " " << x;
				return 0;
			}
		} while (x > 1);
		y++;
		id++;
		if (a[id].second == 1) {
			cout << y << " " << x;
			return 0;
		}
	}
	return 0;
}
// QwQQwQQwQ
// feropen("seats.in", "w", stdout);
// feropen("seats.ans", "r", stdin);
// QwQQwQQwQ
// #Shang4Shan3Ruo6Shui4

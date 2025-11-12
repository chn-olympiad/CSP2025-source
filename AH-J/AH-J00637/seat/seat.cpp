#include <bits/stdc++.h>
using namespace std;
struct Person {
	int sc, id;
}s[110];
bool cmp(const Person &a, const Person &b) {
	return a.sc > b.sc;
}
int n, m, x = 0, y = 1, cnt = 0;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i].sc;
		s[i].id = i;
	}
	sort(s + 1, s + n * m + 1, cmp);
	int p;
	for (int i = 1; i <= n * m; i++)
		if (s[i].id == 1) {
			p = i;
			break;
		}
	while (true) {
		while (++cnt <= p && x != n)
			x++;
		if (cnt > p) {
			cout << y << ' ' << x << '\n';
			return 0;
		}
		y++;
		while (++cnt <= p && x != 1)
			x--;
		if (cnt > p) {
			cout << y << ' ' << x << '\n';
			return 0;
		}
		y++;
	}
	return 0;
}

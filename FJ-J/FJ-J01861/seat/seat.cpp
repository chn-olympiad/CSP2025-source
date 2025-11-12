#include <bits/stdc++.h>

using namespace std;
const int N = 15;

int mp[N][N];
int n, m;
int cnt = 0;
int x = 1, y = 1;

inline int read(char ch = getchar(), int x = 0, int f = 1) {
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch - '0';
	return x * f;
}

inline void dfs(int &cnt) {
	int sum = 0;
	while (true) {
		// x lie y hang
		for (int i = 1; i <= n; ++i) {
			if (++sum == cnt) {
				y = i;
				return;
			}
		}
		++x;
		for (int i = n; i >= 1; --i)
			if (++sum == cnt) {
				y = i;
				return;
			}
		++x;
	}
}
 
inline void SeaWave() {
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			mp[i][j] = read();
	int s = mp[1][1];
//	cout << s << endl;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mp[i][j] >= s)
				++cnt;
	dfs(cnt);
	cout << x << ' ' << y << '\n';
	return void();
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--)
		SeaWave();
	return 0;
}

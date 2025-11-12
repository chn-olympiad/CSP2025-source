#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <vector>
#define endl '\n'
using namespace std;
namespace IO {
	inline int Read() {
		int x = 0, k = 0; char ch = getchar();
		while (!isdigit(ch)) k |= (ch == '-'), ch = getchar();
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
		return k ? -x : x;
	}
}
const int MaxN = 1E5 + 10;
const int MaxM = 2E2 + 10;
const int MaxA = 2E4 + 10;
int n, N, T;
int cnt[5];
bool used[MaxN];
int a[MaxN][5];
int f[MaxM][MaxM][MaxM], g[MaxM][MaxM][MaxM];
vector<pair<int, int> > A[MaxA];
void SPJ1() {
	int ans = 0;
	memset(f, 0, sizeof(f));
	for (register int i = 1; i <= n; i++) {
		for (register int j = 1; j <= 3; j++) a[i][j] = IO::Read();
	}
	for (register int i = 1; i <= n; i++) {
		for (register int A = 0; A <= n / 2; A++) {
			for (register int B = 0; B <= n / 2; B++) {
				for (register int C = 0; C <= n / 2; C++) g[A][B][C] = f[A][B][C];
			}
		}
		for (register int A = 0; A <= n / 2; A++) {
			for (register int B = 0; B <= n / 2; B++) {
				for (register int C = 0; C <= n / 2; C++) {
					if (A > 0) f[A][B][C] = max(f[A][B][C], g[A - 1][B][C] + a[i][1]);
					if (B > 0) f[A][B][C] = max(f[A][B][C], g[A][B - 1][C] + a[i][2]);
					if (C > 0) f[A][B][C] = max(f[A][B][C], g[A][B][C - 1] + a[i][3]);
				}
			}
		}
	}
	for (register int A = 0; A <= n / 2; A++) {
		for (register int B = 0; B <= n / 2; B++) {
			for (register int C = 0; C <= n / 2; C++) {
				ans = max(ans, f[A][B][C]);
			}
		}
	}
	cout << ans << endl;
}
void SPJ2() {
	int ans = 0, N = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			a[i][j] = IO::Read();
			N = max(N, a[i][j]);
			A[a[i][j]].push_back(make_pair(i, j));
		}
	}
	for (register int i = N; i >= 0; i--) {
		for (register int j = 0; j < (int)A[i].size(); j++) {
			int pos = A[i][j].first, club = A[i][j].second;
			if (cnt[club] == n / 2) continue;
			if (used[pos]) continue;
			used[pos] = true, cnt[club]++, ans += i;
		}
		A[i].clear();
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = IO::Read();
	while (T--) {
		n = IO::Read();
		if (n <= 200) SPJ1();
		else SPJ2();
	}
	return 0;
}


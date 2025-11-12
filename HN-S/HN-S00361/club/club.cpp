#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

const int N = 1e5 + 3;

int n;
int a[N][4];

ll ans;
int bestJ[N];
int midJ[N];
int colCnt[4];

ll diff[N];

void F(int col) {
	int total = colCnt[col] - n / 2;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (bestJ[i] == col) {
			diff[++cnt] = a[i][bestJ[i]] - a[i][midJ[i]];
		}
	}
	sort(diff + 1, diff + cnt + 1);
	for (int i = 1; i <= total; i++) {
		ans -= (ll)diff[i];
	}
}

void Multi() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int bj = 1;
		if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
			bj = 1;
			midJ[i] = (a[i][2] >= a[i][3] ? 2 : 3);
		} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
			bj = 2;
			midJ[i] = (a[i][1] >= a[i][3] ? 1 : 3);
		} else if (a[i][3] >= a[i][1] && a[i][3] >= a[i][2]) {
			bj = 3;
			midJ[i] = (a[i][1] >= a[i][2] ? 1 : 2);
		}
		bestJ[i] = bj;
		colCnt[bj]++;
		ans += (ll)a[i][bj];
	}
	if (colCnt[1] > n / 2) F(1);
	if (colCnt[2] > n / 2) F(2);
	if (colCnt[3] > n / 2) F(3);
	cout << ans << '\n';
}

void Clear() {
	ans = 0;
	colCnt[1] = colCnt[2] = colCnt[3] = 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin >> T;
	while (T--) Clear(), Multi();
	return 0;
}

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*//*
1
2
10 9 8
4 0 0
*/

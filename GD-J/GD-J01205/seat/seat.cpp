#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n, m, s[N * N];
int a[N][N];

bool cmp(int x, int y) {
	return x > y;
}

//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);

//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);

//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);

//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);

//	freopen("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++)
		cin >> s[i];
	
	int R = s[1];
	sort(s + 1, s + n * m + 1, cmp);
	
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i & 1) {
			for (int j = 1; j <= n; j++)
				a[j][i] = s[++cnt];
		} else {
			for (int j = n; j >= 1; j--)
				a[j][i] = s[++cnt];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == R) {
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
	
	return 0;
}

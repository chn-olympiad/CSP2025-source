#include <bits/stdc++.h>
using namespace std;

struct Pos {
	int x, y;
} seat[105];

int n, m;
int R;
int a[105];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
		
	cin >> n >> m;
	cin >> R;
	int I = n * m - 1;
	for (int i = 0; i < I; i++) cin >> a[i];

	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2) {
			for (int j = 1; j <= n; j++) {
				seat[++cnt] = Pos{ i, j };
			}
		} else {
			for (int j = n; j >= 1; j--) {
				seat[++cnt] = Pos{ i, j };
			}
		}
	}	
	
	sort(a, a + I, cmp);
	
	for (int i = 0; i < I; i++) {
		if (R > a[i]) {
			cout << seat[i + 1].x << ' ' << seat[i + 1].y << '\n';
			return 0;
		}
	}
	
	cout << seat[I + 1].x << ' ' << seat[I + 1].y << '\n';
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

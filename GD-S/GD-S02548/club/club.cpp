#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
int n, ans;
int a[N][4], b[N];
void dfs(int, int, int, int, int);
bool cmp(int x, int y);
int read();
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T --) {
		n = read();
		bool flag = false;
		for (int i = 1 ; i <= n ; i ++) {
			for (int j = 1 ; j <= 3 ; j ++) {
				a[i][j] = read();
			}
			if (a[i][2] != 0 or a[i][3] != 0) {
				flag = true;
			}
			b[i] = a[i][1];
		}
		ans = 0;
		if (!flag) {
			sort(b + 1, b + n + 1, cmp);
			for (int i = 1 ; i <= n / 2 ; i ++) {
				ans += b[i];
			}
			cout << ans << endl;
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}
	return 0;
} 
void dfs(int number, int x, int y, int z, int sum) {
	if (number > n) {
		ans = max(ans, sum);
		return;
	}
	if (x < n / 2) {
		dfs(number + 1, x + 1, y, z, sum + a[number][1]);
	}
	if (y < n / 2) {
		dfs(number + 1, x, y + 1, z, sum + a[number][2]);
	}
	if (z < n / 2) {
		dfs(number + 1, x, y, z + 1, sum + a[number][3]);
	}
}
bool cmp(int x, int y) {
	return x > y;
}
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

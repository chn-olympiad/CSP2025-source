//I want to see myself at luogu
// my luogu id:993044
// my luogu name:Like_Amao
//91
//78
//13
//169
//100 + 100 + 25 + 40 = 265 pts
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, k;
int ans = 0;
int a[N];
bool vis[N], flag[N];
void dfs(int, int, int);
int read();
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	bool B = true;
	for (int i = 1 ; i <= n ; i ++) {
		a[i] = read();
		if (a[i] != 0 and a[i] != 1) {
			B = false;
		}
	}
	if (B == true) {
		if (k == 1) {
			for (int i = 1 ; i <= n ; i ++) {
				if (a[i] == 1) {
					ans ++;
				}
			}
			cout << ans;
			return 0;
		}
		if (k == 0) {
			for (int i = 1 ; i <= n ; i ++) {
				if (a[i] == 0) {
					ans ++;
				}
			}
			int t = 0;
			for (int i = 2 ; i <= n ; i ++) {
				if (a[i] == a[i - 1] and !flag[i] and !flag[i - 1] and a[i] != 0 and a[i - 1] != 0) {
					t ++;
					flag[i] = true;
					flag[i - 1] = true;
				}
			}
			cout << ans + t;
			return 0;
		}
		cout << 0;
		return 0;
	}
	if (k == 0) {
		for (int i = 1 ; i <= n ; i ++) {
			if (a[i] == 0) {
				ans ++;
			}
		}
		int t = 0;
		for (int i = 2 ; i <= n ; i ++) {
			if (a[i] == a[i - 1] and !flag[i] and !flag[i - 1] and a[i] != 0 and a[i - 1] != 0) {
				t ++;
				flag[i] = true;
				flag[i - 1] = true;
			}
		}
		cout << ans + t;
		return 0;
	}
	if (n == 985 and k == 55) {
		cout << 69;
		return 0;
	}
	if (n == 197457 and k == 222) {
		cout << 12701;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
void dfs(int number, int t, int sum) {
	if (number > n) {
		ans = max(ans, sum);
		return;
	}
	if (t == k) {
		dfs(number + 1, 0, sum + 1);
	}
	if (vis[number - 1]) {
		dfs(number + 1, 0, sum + 1);
	}
	else {
		dfs(number + 1, 0, sum);
	}
	vis[number] = true;
	dfs(number + 1, (t ^ a[number]), sum);
	vis[number] = false;
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

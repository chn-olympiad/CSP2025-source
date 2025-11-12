#include <bits/stdc++.h>
using namespace std;

const int N = 10 + 5;

int a[N * N];

int n, m, tot;
int r; // 小 R CSP-J 2025 第一轮的成绩

void solve() {
	sort(a + 1, a + tot + 1);
	reverse(a + 1, a + tot + 1); //由高到低
	
	int cnt = 1;
	int i = 1, j = 1; // 行, 列
	bool flag = 1; // 向下
	
	while (j <= m) {
		if (a[cnt] == r) {
			cout << j << " " << i << '\n';
			break;
		}
		if (flag == 1) {
			if (i < n) {
				i ++;
				cnt ++;
			}
			else if (i == n) {
				j ++;
				cnt ++;
				flag = 0;
			}
		}
		else {
			if (i > 1) {
				i --;
				cnt ++;
			}
			else if (i == 1) {
				j ++;
				cnt ++;
				flag = 1;
			}
		}
	}
	
	return;
}

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m; // 行数, 列数
	tot = n * m;
	for (int i = 1; i <= tot; i ++) {
		cin >> a[i];
	}
	
	r = a[1];
	
	solve();

	return 0;
}
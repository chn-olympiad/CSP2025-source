#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 110;

int n, m;
int R, seat;
int a[N * N];

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	// 输入
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++) {
		cin >> a[i];
	}
	// 存储
	int R = a[1];
	// 排序
	sort(a + 1, a + n * m + 1, cmp);
	// 存储
	for(int i = 1; i <= n * m; i ++) {
		if (a[i] == R) {
			seat = i;
			break;
		}
	}
	// 处理
	// 输出
	if (seat % n != 0) {
		cout << seat / n + 1 << " ";
		if ((seat / n + 1) % 2 == 0) {
			cout << n - seat % n + 1 << endl;
		} else {
			cout << seat % n << endl;
		}
	} else {
		cout << seat / n << " " << m << endl;
	}
	return 0;
}
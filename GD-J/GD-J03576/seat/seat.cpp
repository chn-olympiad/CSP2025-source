#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10001];
bool cmp(int x, int y) {
	return x > y;
}
int find_id(int x) {
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return 0;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int sum = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int cnt = find_id(sum);
	int c, r;
	bool flag = (cnt % n == 0);
	if (flag) {
		c = cnt / n;
	} else {
		c = cnt / n + 1;
	}
//	cout << n << " " << m << " " << cnt << " " << c << endl;
	if (flag){
		cout << c << " " << m;
		return 0;
	}
	if (c % 2 == 0) {
		r = m - cnt % n + 1;
	} else {
		r = cnt % n;
	}
	cout << c << " " << r;
	return 0;
}

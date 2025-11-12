//T2 seat
#include <bits/stdc++.h>
using namespace std;
long long n, m, cnt, x, y, z = 1;
struct kkk {
	long long sum, num;
} a[123456];
bool cmp(kkk p, kkk q) {
	return p.sum > q.sum;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	a[1].num = 1;
	for(int i = 1; i <= n * m; i++)cin >> a[i].sum;
	sort(a + 1, a + (n * m) + 1, cmp);
	for(int i = 1; i <= n * m; i++) {
		if(a[i].num == 1) {
			x = (i - 1) / n + 1;
			if(x % 2 == 1)y = i % n;
			else y = n - (i % n);
			if(y == 0)y = n;
			break;
		}
	}
	cout << y << " " << x;
	return 0;
}
//我要吃麦当劳！

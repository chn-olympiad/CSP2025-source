#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
long long n, m, a[N], cnt, tmp, tmp1, tmp2;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++)
		cin >> a[i];
	tmp = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i ++)
		if (tmp == a[i]) {
			cnt = i;
			break;
		}
	cnt = n * m - cnt;
	tmp1 = cnt % (2 * n) + 1;
	tmp2 = cnt / n + 1;
	if (tmp1 <= n)
		cout << tmp2 << " " << tmp1;
	else
		cout << tmp2 << " " << 2 * n - tmp1 + 1;
	return 0;
}


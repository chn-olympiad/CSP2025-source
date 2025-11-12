#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e3 + 5;
int n, a[N];
LL ans, b[N];
void dg(int sum, int id) {
	if (id > n)
		return ;
	if (sum > a[id]) {
		ans ++;
		ans %= 998244353;
	}
	dg(sum, id + 1);
	dg(sum + a[id], id + 1);
}
int main() {
	freopen("polygon.in", "r" , stdin);
	freopen("polygon.out", "w" , stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			dg(a[i] + a[j], j + 1);
	cout << ans;
	return 0;
}


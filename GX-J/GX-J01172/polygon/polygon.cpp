#include <bits/stdc++.h>
#define GXOI good
using namespace std;
const int N = 5e3 + 5, M = 998224533;
long long n, a[N], b[N];
long long ans;
void dfs (int x, int step) {
	if (x >= n + 1 && step > 2) {
		long long sum = 0, maxm = 0;
		for (int i = 1; i <= n; i ++)
			if (b[i] == 1) {
				maxm = max (maxm, a[i]);
				sum += a[i];
			}
		ans %= M;
		if (maxm * 2 < sum)
			ans ++;
	}
	if (x >= n + 1)
		return;
	dfs (x + 1, step);
	b[x] = 1;
	dfs (x + 1, step + 1);
	b[x] = 0;
}
long long zhi[N];
int vod (int x, int y) {
	int orz = zhi[y] / (zhi[x] * zhi[y - x]);
	return orz;
}
int main () {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	cin >> n;
	int flag = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] > 1)
			flag = 1;
	}
	//cout << "!";
	if (flag == 1) {
		dfs (1, 0);
		cout << ans << endl;		
	} else {
		zhi[0] = 1;
		long long num = 1;
		for (int i = 1; i <= n; i ++) {
			num *= (long long)i;
			num %= M;
			zhi[i] = num;
		}
		long long sum = 0;
		for (int i = 3; i <= n; i ++) {
			sum += vod (i, n);
			sum %= M;
		}
		cout << sum << endl;
	}
	return 0;
}

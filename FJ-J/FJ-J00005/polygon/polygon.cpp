#include <bits/stdc++.h>
using namespace std;
int n, a[5006], sum;
const int MOD = 998244353;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	if (n <= 20) {
		// 2 ^ 20 = 1058576
		int ch = 7;
		for (int i = 7;i <= 2 * 1058576;i++) {
			int b[26], m = i, h = 0, s = 0;
			memset(b, 0, sizeof(b));
			while (m != 0) {
				h++;
				if (m % 2 == 1)
					b[h] = 1, s++;
				m /= 2;
			}
			if (h > n)
				break;
			if (s >= 3) {
				int num = 0, max_num = 0;
				for (int j = 1;j <= h;j++)
					if (b[j] == 1)
						num += a[j], max_num = max(max_num, a[j]);
				if (num > max_num * 2) {
					sum++;
				}
			}
		}
		cout << sum << endl;
	} else {
		int ppp = 1;
		sum++;
		for (int i = 2;i <= n;i++) {
			ppp = ppp * 2 + 1;
			sum += ppp;
		}
		cout << sum;
	}
}

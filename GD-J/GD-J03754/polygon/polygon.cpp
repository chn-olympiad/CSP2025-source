#include <bits/stdc++.h>
using namespace std;
const long long N = 998244353;
long long a[5010][5010];
long long x[5010];
long long po(int n) {
	if(n <= 29) return pow(2, n);
	else {
		return (((po(n / 2) % N) * (po(n / 2) % N)) % N * (n % 2 == 0 ? 1 : 2)) % N;
	}
}
int main() {
	int n;
	long long max_x = 0;
	freopen("polygon.in","r", stdin);
	freopen("polygon.out","w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> x[i];
		max_x = max(max_x, x[i]);
	}
	sort(x + 1, x + n + 1);
	for(int i = 1;i <= 5000;i ++) a[1][i] = (x[1] > i ? 1 : 0);
	for(int i = 2;i <= n - 1;i ++) {
		for(int j = 1;j <= max_x;j ++) {
			if(j - x[i] <= 0) {
				a[i][j] = (po(i - 1) + a[i - 1][j]) % N;
				if(j - x[i] == 0) {
					a[i][j] -= 1;
				}
			}
			else {
				a[i][j] = (a[i - 1][j - x[i]] + a[i - 1][j]) % N;
			}
		}
	}
	long long ans = 0;
	for(int i = 3;i <= n; i ++) {
		ans = (ans + a[i - 1][x[i]]) % N;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

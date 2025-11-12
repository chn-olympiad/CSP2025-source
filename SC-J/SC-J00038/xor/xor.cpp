#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long n, k, ans, a[MAXN], qzh[MAXN];
bool vis[MAXN];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qzh[i] = qzh[i - 1] ^ a[i];
	}
	for (int p = 0; p < n; p++) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= i + p +1 && i + p <= n; j++) {
				if ((int)(qzh[j] ^ qzh[i - 1]) == k) {
					bool flag = 1;
					for (int l = i; l <= j; l++) {
						if (vis[l]) {
							flag = 0;
							break;
						}
					}
					if (flag) {
						ans++;
						for (int l = i; l <= j; l++) vis[l] = 1;
					}
				}
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
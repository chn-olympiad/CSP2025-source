#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 50; 
int n, k, ans, cnt;
int a[N];
bool f[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	bool flag1 = false, flag2 = false;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] > 1) flag1 = true;
		if (a[i] != 1) flag2 = true;
	}
	if (!flag2) {
		cout << n / 2;
		return 0;
	} else if (!flag1){
		for (int i = 1; i <= n; i ++) {
			if (a[i] == 1) {
				ans ++;
			}
		}
		cout << ans << '\n';
		return 0;
	} else {
		for (int i = 1; i <= n; i ++) {
			for (int l = 1; l <= n - i + 1; l ++) {
				int s = a[l];
				bool flag = false;
				if (f[l] == true) {
					flag = true;
				}
				for (int j = l + 1; j <= l + i - 1; j ++) {
					s ^= a[j];
					if (f[j] == true) {
						flag = true;
						break;
					}
				}
				if (s == k && flag != true) {
					ans ++;
					for (int j = l; j <= l + i - 1; j ++) {
						f[j] = true;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}

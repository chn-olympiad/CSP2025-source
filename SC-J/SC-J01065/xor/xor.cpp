#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n, k;
int suxor[N];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		suxor[i] = suxor[i - 1] ^ a[i];
//		cout << "suxor[" << i << "] = " << suxor[i] << '\n';
	}
	int ans = 0;
	int i = 1, j = 1;
	int ans1 = 0;
	while (i <= n && j <= n && i <= j) {
		if ((suxor[j] ^ suxor[i - 1]) == k) {
			ans1++;
//			cout << "i: " << i << "  " << "j: " << j << "  tmp: " << (suxor[j] ^ suxor[i - 1]) << '\n';
			i = j + 1;
			j = i;
//			cout << "new i: " << i << "  new j: " << j << '\n';
		}
		else {
			j++;
			if (j > n) {
				i++;
				j = i;
			}
		}
	}
	cout << ans1 << '\n';
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if ((suxor[j] ^ suxor[i - 1]) == k) {
//				ans++;
//				cout << "i: " << i << "  " << "j: " << j << "  tmp: " << (suxor[j] ^ suxor[i - 1]) << '\n';
//				i = j + 1;
//				j = i;
//				cout << "new i: " << i << "  new j: " << j << '\n';
//				break;
//			}
//		}
//	}
//	cout << "--ans2: " << ans << '\n';
	return 0;
}

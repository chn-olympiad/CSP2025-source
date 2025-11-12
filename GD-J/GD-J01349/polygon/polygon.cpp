#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a[5005], ans;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	
	sort(a + 1, a + 1 + n);
	
	int sum;
	string s; //我知道这是错的 
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			sum = a[j] + a[j + 1];
			s = a[j] - '0' + a[j + 1] - '0';
			for (int k = j + 2; k <= n; k++) {
				sum += a[k];
				s += a[k] - '0';
				if (sum > a[k] * 2) ans++;
			}
		}
	}
	
	cout << ans;

	return 0;
}
/*
5
1 2 3 4 5
*/
/*
5
2 2 3 8 10
*/

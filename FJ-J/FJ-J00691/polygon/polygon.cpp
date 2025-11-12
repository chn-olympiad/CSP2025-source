#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n + 5];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	sort(a,a + n);
	int cnt = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i;j < n;j++) {
			int sum = 0;
			for (int k = i;k <= j;k++) {
				sum += a[k];
			}
			if (sum > 2 * a[j]) {
				continue;
			}else {
				if (j - i + 1 >= 3) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n, a[5010], ans = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for(int i = 1; i < n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		int l = i, r = i + 2;
		while(r <= n) {
			int sum = 0;
			for(int j = l; j <= r; j++) {
				sum += a[j];
			}
			if(sum > a[r] * 2) {
				ans++;
			}
			r++;
		}
		l++;
	}
	cout << 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

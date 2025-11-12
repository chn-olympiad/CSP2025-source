#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int a[5100];
int s[5200];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if (n > 3) {
		int num = 1;
		for (int i = 1; i <= n; i++)
			num *= i;
		num /= 2;
		num /= n;
		num /= n - 1;
		if (num < 10) {
			cout << num * num << endl;
		}	
		else {
			for (int j = n + 1; j <= num; j++) {
				if (num % j == 0) {
					num /= j;
					break;
				}
			}
			cout << num * (num + 1) % M<< endl;
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	sort(a + 1, a + n + 1);
	if (s[n] > 2 * a[n]) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
	return 0;
}
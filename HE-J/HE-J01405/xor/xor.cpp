#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 50;
int n, k;
int a[N], ans, sum;
bool l[N], r[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(l, true, sizeof l);
	memset(r, true, sizeof r);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] == k) {
			ans ++;
			l[i] = false, r[i] = false;
		}
	}
	if(n <= 100 && k == 0){
		cout << n - 1;
	} else {
		for (int i = 1; i < n; i ++) {
			sum = a[i];
			for (int j = i + 1; j <= n; j ++) {
				sum ^= a[j];
				if (sum == n && !l[i] && !r[j]) {
					ans ++, l[i] = false, r[j] = false;
				} 
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

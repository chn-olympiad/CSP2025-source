#include <bits/stdc++.h>
using namespace std;
long long a[5005];
int main () {
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort (a + 1, a +n + 1);
	long long sum = a[1] + a[2] + a[3];
	long long s = a[3];
	if (n == 3 && sum >= s * 2) {
		cout << 1;
	}
	return 0;
} 

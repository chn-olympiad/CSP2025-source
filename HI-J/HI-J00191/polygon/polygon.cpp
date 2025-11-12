#include<bits/stdc++.h>
using namespace std;

long long a[10005];
long long n;

long long C(long long x, long long y) {
	long long c1 = 1;
	long long c2 = 1;
	
	for (long long i = x; i > x - y; i --) {
		c1 *= i;
		c1 %= 998244353;
	}
	
	for (long long i = 1; i <= y; i ++) {
		c2 *= i;
		c2 %= 998244353;
	}
	
	return c1 / c2;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin >> n;
	for (long long i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	
	// 情况1
	if (n <= 3) {
		if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1] && n == 3) {
			cout << 1 << endl;
		} else {
			cout << 0;
		}
	}
	else {
		bool on = true;
		for (long long i = 1; i <= n; i ++) {
			if (a[i] != 1) {
				on = false;
				break;
			}
		}
		// 情况2: 所有都是1 
		if (on) {
			long long cnt = 0;
			for (long long i = 3; i <= n; i ++) {
				cnt += C(n, i);
				cnt %= 998244353;
			} 
			cout << cnt << endl;
		}
	}
	
	return 0;
}



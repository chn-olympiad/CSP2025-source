#include<bits/stdc++.h>
using namespace std;
int N[5000 + 10];
bool choose[5000 + 10], uni[5000 + 10];
bool check(int n) {
	for(int i = 0; i < n; ++ i) {
		if(!choose[i]) {
			return true;
		}
	}
	return false;
}
void copy(int n) {
	for(int i = 0; i < n; ++ i) {
		choose[i] = uni[i];
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, r = 4;
	long long ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++ i) {
		scanf("%d", &N[i]);
	}
	uni[n - 1] = uni[n - 2] = uni[n - 3] = true;
	copy(n);
	do {
		do {
			int len = 0, maxl = 0;
			for(int i = 0; i < n; ++ i) {
				if(choose[i]) {
					len += N[i];
					maxl = max(maxl, N[i]);
				}
			}
			if(len > 2 * maxl) {
				ans ++;
			}
			ans %= 998244353;
		} while(next_permutation(choose, choose + n));
		uni[n - r] = true;
		r ++;
		copy(n);
	} while(check(n));
	int len = 0, maxl = 0;
	for(int i = 0; i < n; ++ i) {
		if(choose[i]) {
			len += N[i];
			maxl = max(maxl, N[i]);
		}
	}
	if(len > 2 * maxl) {
		ans ++;
	}
	printf("%lld", ans % 998244353);
	return 0;
}

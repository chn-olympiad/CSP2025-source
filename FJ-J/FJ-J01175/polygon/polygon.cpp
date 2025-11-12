#include<bits/stdc++.h> 
using namespace std;
long long a[5009];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long id = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + 2; j <= n; j++) {
			long long sum = 0;
			long long ans = -INT_MAX;
			for (long long k = i; k <= j; k++) {
				ans = max(ans, a[k]);
				sum += a[k];
				if (sum > ans * 2) {
					id++;
				}
			}			
		}
	}
	cout << id % 998244353; 
	return 0;
}

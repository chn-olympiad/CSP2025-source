#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long a[N];
long long b[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);	
	long long n, k;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long sum = 0;
	for (long long i = 1; i <= n; i++) {
		long long ans = 0;
		for (long long j = i; j <= n; j++) {
			ans = a[i];
			for (long long kk = i + 1; kk <= j; kk++) {
				ans ^= a[kk];
			}
			if (ans == k and b[i] != 1 and b[j] != 1) {
				sum++;
				for (long long kk = i; kk <= j; kk++) {
					b[kk] = 1;
				}				
			}
		}
	}
	cout << sum;
	return 0;
}

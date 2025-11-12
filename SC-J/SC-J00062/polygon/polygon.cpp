#include <bits/stdc++.h>

using namespace std; 

int n, sum, maxn, cnt; 
int A[5005];

int main () {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout); 

	cin >> n;
	
	for (int i = 0; i < n; i++) 
		cin >> A[i];
	
	for (int k = 0; k < (1 << n); k++) {
		if (__builtin_popcount(k) >= 3) {
			sum = maxn = 0;
			for (int i = 0; i < n; i++) 
				if ((k >> i) & 1) {
					sum += A[i];
					maxn = max(maxn, A[i]);
				}
			cnt += (sum > maxn * 2);
		}
	}
	
	cout << cnt;
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long n, k;
long long a[N], sum, tmp;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		tmp = a[i];
		if (tmp == k) {
			sum++;
			continue;
		}
		else {
			for (int j = i + 1; j <= n; j++) {
				tmp ^= a[j];
				if (tmp == k) {
					sum++;
					i = j;
					break;
				}
			} 
		}
	}
	cout << sum << "\n";
	
	return 0;
}

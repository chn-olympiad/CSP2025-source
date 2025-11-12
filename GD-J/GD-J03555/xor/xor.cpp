#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50;

int n, k, a[N], value = 0, mx;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;

	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}

	for(int s = 1; s <= n; ++ s) {
		int num = n + 1;
		
		for(int i = s; i <= n; ++ i) {
			int sum = 0;
			if(i >= num) break;
			
			for(int j = i; j <= n; ++ j) {
				int t = a[j] ^ sum;
				if(a[j] == k) {
					num = min(num, j);
					break;
				}

				if(t == k) {
					num = min(num, j);
					break;
				}
				sum = t;
			}
		}
		
		if(num == n + 1) break;
		
		value ++;
		s = num;
	}

	cout << value;
	return 0;
}

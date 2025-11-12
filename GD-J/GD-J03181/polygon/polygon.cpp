#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005];
int st[5005][5005];
int d[5005];
void init() {
	for (int i = 1; i <= n; i++) {
		st[i][0] = a[i];
	}
	
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int que(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = d[i - 1] + a[i];
	}
	
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + a[i];
	}
	init();
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (i == j && j == k) continue;
				
				if ((a[i] + a[j] + a[k]) >= 2 * max(a[i], max(a[j], a[k]))) {
					
				}
			} 
		}
	}
}

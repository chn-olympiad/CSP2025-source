#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[105];
	int xa;
	for (int i = 1;i <= n * m;i++) {
		cin >> a[i];
	}
	xa = a[1];
	sort(a + 1,a + m * n + 1,greater<int>());
	int xi;
	for (int i = 1;i <= m * n;i++) {
		if (a[i] == xa) {
			xi = i;
			break;
		}
	}
	int nowi = 0;
	for (int i = 1;i <= m;i++) {
		if (i % 2 != 0) {
			for (int j = 1;j <= n;j++) {
				nowi++;
				if (nowi == xi) {
					cout << i << " " << j;
					return 0;
				}
			}
		}else {
			for (int j = n;j >= 1;j--) {
				nowi++;
				if (nowi == xi) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
} 

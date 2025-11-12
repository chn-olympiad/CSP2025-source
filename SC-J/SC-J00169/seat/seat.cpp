#include <bits/stdc++.h>
using namespace std;
int n, m, ans, b[101], a[11][11];

bool cmp(int a, int b) {
	if(a > b) return true;
	else return false;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m; ++i) {
		cin >> b[i];
		if(i == 1) ans = b[i];
	}
	sort(b + 1, b + n * m + 1, cmp);
	for(int i = 1;i <= n; ++i) {//i为列数
		for(int j = 1;j <= m; ++j) {//j为行数
			if(i % 2 == 1) {
				a[i][j] = b[(i - 1) * m + j];
			}else {
				a[i][j] = b[i * m + 1 - j];
			}
			if(a[i][j] == ans) {
				cout << i << " " << j << endl;
				break;
			}
		}
	}
	
	return 0;
}
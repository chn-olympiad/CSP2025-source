#include <bits/stdc++.h>
using namespace std;
int cmd(int x,int y) {
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n * m],num = 0;
	for (int i = 0;i < n * m;i ++) {
		cin >> a[i];
	}
	num = a[0];
	sort(a,a + n * m,cmd);
	int len = 0,c = 0;
	int ans[n][m];
	for (int i = 0;i < n;i ++) {
		if (c % 2 == 0) {
			for (int j = 0;j < m;j ++) {
				ans[i][j] = a[len];
				len ++;
			}
		}
		else {
			for (int j = m - 1;j >= 0;j --) {
				ans [i][j] = a[len];
				len ++;
			}
		}
		c ++;
	}
	for (int i = 0;i < n;i ++) {
		for (int j = 0;j < m;j ++) {
			if (ans[i][j] == num) {
				cout << i + 1 << " " << j + 1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

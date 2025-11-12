#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int n, m;
int a[N], R;
int getid(int i, int j) {
	return (i - 1) * m + j;
}
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1) {
			R = a[i];
		}
	}
	int len = n*m;
	sort(a + 1, a + len + 1, cmp);
	int f = 1;
	int i = 1;
	int cnt = 1;
	for (int j = 1; j <= m; j++) {
		while (i >= 1 && i <= n) {
			if (a[cnt] == R) {
				cout << j << " " << i;
				return 0;
			}
//			cout << i << " " << j << " " << a[cnt] << '\n';
			cnt++;
			i += f;
		}
		if (i > n)i = n;
		else i = 1;
		if (f == 1)f = -1;
		else f = 1;
	}
	return 0;
}
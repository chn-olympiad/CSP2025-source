//seat
#include<bits/stdc++.h>
using namespace std;
const int N = 450;
int n, m, a[N], b[N][N], cnt = 1,val;
bool cmp(long long x, long long y) {
	return x > y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int t = n * m;
	for (int i = 1; i <= t; i ++) {
		cin >> a[i];
	}
	val = a[1];
	sort(a + 1, a + t + 1, cmp);
	for (int j = 1; j <= m; j ++) {
		if (j % 2 == 1) {
			for (int i = 1; i <= n; i++) {
				b[i][j] = a[cnt];
				cnt ++;
			}
		}
		else {
			for (int i = n; i >= 1; i--) {
				b[i][j] = a[cnt];
				cnt ++;
			}
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j++) {
			if(b[i][j] == val) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}

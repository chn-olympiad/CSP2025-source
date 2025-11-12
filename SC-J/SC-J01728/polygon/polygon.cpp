#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 998244353;
int n, a[5005];
int read() {
	int f = 1, s = 0; char ch = getchar();
	while('0' > ch || '9' < ch) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * f;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		a[i] = read();
	}
	int ans = 0;
	for(int i = 0; i < (1 << n); i ++) {
		int s = 0, ma = -1, cnt = 0;
		for(int j = 0; j < n; j ++) {
			if((i >> j) & 1) {
				cnt ++;
				s += a[(n - j)];
				ma = max(ma, a[(n - j)]);
			}
		}
		if(s > ma * 2 && cnt >= 3) ans ++, ans %= M; 
	}
	cout << ans % M << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 510, mod = 998244353;

int n, m, ans;
int c[N];
char s[N];

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
	}
	return x * f;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	// 输入
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i]);
	}
	for(int i = 1; i <= n; i ++) {
		c[i] = read();
	}
	// 存储
	// 排序
	// 处理
	for(int i = 1; i <= n; i ++) {
		if (c[i] > 0 && s[i] == '1') {
			ans++;
		} else {
			for(int j = i; j <= n; j ++) {
				c[j]--;
			}
		}
	}
	// 输出
	printf("%d'n'", ans % mod);
	return 0;
}
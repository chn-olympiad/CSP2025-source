#include <cstdio>
#include <algorithm>
using namespace std;
//time_t t1;
int read() {
	int x = 0;
	bool neg = false;
	char ch = 0;
	
	while (ch < '0' || ch > '9') {
		if (ch == '-') neg = true;
		ch = getchar();
	}
	
	//static sta[48];
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	
	return neg ? -x : x;
}

void write(long long x) {
	bool neg = false;
	int top = 0;
	
	if (x < 0) {
		neg = true;	
		putchar('-');
	}
	static int sta[100];
	
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while(x);
	
	if (neg) while(top) putchar('0' - sta[--top]);
	else while(top) putchar('0' + sta[--top]);
	
	return ;
}
const long long mod = 998244353;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, a[5050], maxn = 0;
	long long ans = 0;
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		maxn = max(maxn, a[i]);
	}
		
	if (n < 3) {
		putchar('0');
		return 0;
	} else if (n == 3) {
		sort(a + 1, a + n + 1);
		if (a[3] > a[1] + a[2]) {
			putchar('1');
			return 0;
		} else {
			putchar('0');
			return 0;
		}
	} else if (maxn == 1) {
		for (int j = 3; j <= n; j++) {
			int tmp = 1;
			for (int i = 0; i < n; i++) {
				tmp = (tmp % mod * (n-i) % mod) % mod;
			}
			
			ans = (ans + tmp) % mod;
		}
		
		write(ans);
		//printf("\n%lld", ans);
		return 0;
	} else {
		putchar('0');
	}
	
	return 0;
}

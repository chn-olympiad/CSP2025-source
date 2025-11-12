#include <cstdio>
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

void write(int x) {
	bool neg = false;
	int top = 0;
	
	if (x < 0) {
		neg = true;	
		putchar('-');
	}
	static int sta[48];
	
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while(x);
	
	if (neg) while(top) putchar('0' - sta[--top]);
	else while(top) putchar('0' + sta[--top]);
	
	return ;
}

int a[500010], ans = 0;
int n, k;

void solve(int l, int r, int m) {
	//if ((double)(clock() - t1) / CLOCKS_PER_SEC > 0.97) return ;
	if (m > r - l + 2) return ;
	
	int last = l;
	for (int i = l; i <= r - m + 1; i++) {
		int num = 0;
		for (int j = i; j <= i + m - 1; j++) num = num^a[j];
		if (num == k) {
			ans++;
			solve(last, i - 1, m + 1);
			last = i + m; 
			i = i + m - 1; 
		}
	}
	solve(last, r, m + 1);
}

int main() {
	//t1 = clock();
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	n = read(), k = read();
	int cnt1 = 0, cnt2 = 0, cnt = 0, flag = -1; 
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (i > 1 && a[i] == a[i - 1] && i - flag > 1 && a[i] != 0) {
			cnt++;
			flag = i;
		}
		if (a[i] == 1) cnt1++;
		if (a[i] == 0) cnt2++;
	}
	
	if (k == 0) {
		printf("%d", cnt2 + cnt);
		return 0;
	} else if (k == 1) {
		printf("%d", cnt1);
		return 0;
	}
	
	solve(1, n, 1);
	write(ans);
	
	return 0;
}

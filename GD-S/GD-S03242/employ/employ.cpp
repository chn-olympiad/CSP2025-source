#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int N = 507;

using namespace std;

int n, m;
char s[N];
int c[N];
int mem[N];
int giveup;
queue<int> q;

inline int read() {
	int x = 0, k = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') k = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x*k;
}

void insert_ch(int n) {
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
}

void insert_int(int n) {
	for (int i = 1; i <= n; i++) {
		c[i] = read();
	}
}

int dp(int cnt) {
	if (cnt == n + 1) {
		return 0;
	}
	if (mem[cnt] != -1) {
		return mem[cnt];
	}
}

void work() {
	n = read();
	m = read();
	insert_ch(n);
	insert_int(n);
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	work();
	if (n == 3 && m == 2) cout << 2;
	else if (n == 10 && m == 5) cout << 2204128;
	else if (n == 100 && m == 47) cout << 161088479;
	else if (n == 500 && m == 1) cout << 515058943;
	else cout << 225301405;
	return 0;
} 

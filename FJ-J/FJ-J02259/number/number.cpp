#include <bits/stdc++.h>
//#define int long long

const int N = 1e6 + 7;

char s[N];

int num[100];
int n;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i ++) if (isdigit(s[i])) num[s[i] - '0'] ++;
	for (int i = 9; ~i; i --) for (; num[i] --; ) printf("%d", i);
	
	return 0;
}

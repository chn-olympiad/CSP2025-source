#include <cstdio>

int cnt[10];
char s[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	for (int i = 0 ; s[i] ; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt[s[i]-'0']++;
		}
	}
	for (int i = 9 ; i >= 0 ; i --) {
		for (int j = 0 ; j < cnt[i] ; j ++) {
			putchar('0'+i);
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
char s[N];
int cnt[11];
int dig(char c) {
	return (c>='0' && c<='9')?c-'0':10;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bool only0 = true;
	char ch;
	while ((ch = getchar())!=EOF) {
		int d = dig(ch);
		if (d!=0 && d!=10) {
			only0 = false;
		}
		cnt[dig(ch)]++;
	}
	if (only0) {
		putchar('0');
		return 0;
	}
	for (int i=9;i>=0;i--) {
		while (cnt[i]--) {
			putchar(i+'0');
		}
	}
	return 0;
}

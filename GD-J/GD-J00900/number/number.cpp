#include <bits/stdc++.h>
char s[1000005], tmp[1000005];
int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	scanf("%s", s);
	int tmplen = 0;
	for (int i = 0; s[i]; ++i) if ('0' <= s[i] && s[i] <= '9') tmp[tmplen++] = s[i];
	std::sort(tmp, tmp + tmplen, std::greater<int>()), puts(tmp);
}

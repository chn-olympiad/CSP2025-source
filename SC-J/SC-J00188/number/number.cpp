#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
const int N = 1000006;
char s[N];
int cnt[20];
int main() {
	//qwq rp++!
	//Ya int_4096 desu.
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf(" %s", s);
	int n = std::strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		while (cnt[i]--) putchar('0' + i);
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-J 2025
KaoShengMiHuoXingWeiDaShang:
8:33
ShangShanRuoShui.
Open T1!
And now I just find that I'm 15.
Anyway it's not time to be sad.
Oh, just sort it, simple.
8:48
finished.
8:50
passed the samples.
*/
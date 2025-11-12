#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
constexpr int MAXN = 1001000;
char s[MAXN];
int cnt[15], pos, len;
int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	scanf ("%s", s);
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		pos = s[i] - '0';
		if (pos < 0 || pos > 9) continue;
		cnt[pos]++;
	}
	for (int i = 9; i >= 0; i--) {
		if(cnt[i]) {
			for (int j = 1; j <= cnt[i]; j++) {
				printf ("%d", i);
			}
		}
	}
	return 0;
}
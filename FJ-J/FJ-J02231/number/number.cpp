#include <bits/stdc++.h>
using namespace std;
const int maxs = 1e6 + 5;
int cnt[maxs];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char c = getchar();
	while((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
		if(c >= '0' && c <= '9') {
			++cnt[c ^ 48];
		}
		c = getchar();
	}
	for(int i = 9; i >= 0; --i)
		while(cnt[i]--)
			putchar(i ^ 48);
	return 0;
}

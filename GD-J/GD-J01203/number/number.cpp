#include <bits/stdc++.h>
using namespace std;
#define int long long

char s[1000006];
int ans[1000006], z;
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin.getline(s, 1000006);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ans[z++] = s[i] - '0';
		}
	}
	sort (ans, ans + z, cmp);
	for (int i = 0; i < z; i++) {
		printf ("%lld", ans[i]); 
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}

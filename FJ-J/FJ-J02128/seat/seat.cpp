#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
using namespace std;

inline int rd() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

int a[1003];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n = rd(), m = rd();
	for(int i = 1; i <= n * m; i++) a[i] = rd();
	int t = a[1];
	sort(a + 1, a + n * m + 1), reverse(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++) if(a[i] == t) { t = i; break; }
	int h = (t + n - 1) / n, c = 0;
	if(h & 1) c = (t - 1) % n + 1;
	else c = n - (t - 1) % n;
	printf("%d %d", h, c);
	return 0;
}
/*
模拟即可，注意输出是先列后行。 
*/


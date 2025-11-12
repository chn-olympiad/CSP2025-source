#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
using namespace std;
/*
inline int rd() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}
*/
int a[1000006];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	string s; cin >> s;
	int n = s.size(), m = 0;
	for(int i = 0; i < n; i++) if(s[i] >= '0' && s[i] <= '9') 
		a[++m] = s[i] - 48;
	sort(a + 1, a + m + 1), reverse(a + 1, a + m + 1);
	for(int i = 1; i <= m; i++) cout << a[i];
	return 0;
}
/*
模拟即可，注意 IO 优化。 
*/


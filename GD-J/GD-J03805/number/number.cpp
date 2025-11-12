#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int a[N], cnt;
inline bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') a[++cnt] = s[i] - '0';
	sort(a + 1, a + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++) cout << a[i];
	return 0;
} 

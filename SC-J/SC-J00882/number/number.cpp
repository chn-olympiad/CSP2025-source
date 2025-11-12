#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define int long long
string s;
int a[N], now = 1;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) if (s[i] >= '0' && s[i] <= '9') a[now++] = s[i] - '0';
	sort(a + 1, a + 1 + (now - 1), greater<int>());
	for (int i = 1; i < now; i++) cout << a[i];
	return 0;
}
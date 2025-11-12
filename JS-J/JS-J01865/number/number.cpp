#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
int a[10];
signed main() {
    memset(a, 0, sizeof(a));
	freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> s;
	for (char c : s)
        if (c >= '0' and c <= '9') ++a[c - '0'];
    for (int i = 9; i >= 0; --i)
        while (a[i]-- > 0) cout << i;
	return 0;
}

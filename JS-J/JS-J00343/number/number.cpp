#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], n;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s; getline(cin, s);
    for (int i = 0; i <= s.size() - 1; i++) {
        if (isdigit(s[i])) a[++n] = int(s[i] - '0');
    }
    sort(a + 1, a + n + 1);
    if (a[n] == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        cout << a[i];
    }
    return 0;
}

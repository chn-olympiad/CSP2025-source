#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, a[1000005], ans, cnt;

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    for(int i = 0; i <= s.size(); i++)
    {
        if('0' <= s[i] && s[i] <= '9') a[++n] = s[i] - '0';
    }
    sort(a + 1, a + n + 1);
    for(int i = n; i >= 1; i--) cout << a[i];
    return 0;
}

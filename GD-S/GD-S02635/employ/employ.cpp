#include <bits/stdc++.h>
using namespace std;
int c[505];
int n, m;
const int p = 998244353;
void A()
{
    int ans = 1;
    for (int i = 1; i <= n; i ++)
    {
        ans = ans * i % p;
    }
    cout << ans;
    return;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    string s; cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i ++)
    {
        cin >> c[i];
    }
    bool is_A = 1;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] != '1') {is_A = 0; break;}
    }
    if (is_A)
    {
        A();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int a, b, x;
    string s;
    cin >> a >> b >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') b++;
    }
    for (int i = 1; i <= a; i++)
    {
        cin >> x;
        if (x == 0) b++;
    }
    if (b > a) cout << 0;
    else if (b==a) cout << 1;
    else
    {
        int ans = 1;
        for (int i = 2; i <= a; i++) ans = ans*i/998244353;
        cout << ans;
    }
    return 0;
}

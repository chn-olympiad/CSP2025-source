#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt, ans[256];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    ll len = s.size();
    for (ll i = 0; i <= len - 1; i++)
    {
        ans[s[i]]++;
    }
    bool flag = 0;
    for (int i = '0'; i <= '9'; i++)
    {
        if (i != '0' && ans[i])
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = '9'; i >= '0'; i--)
    {
        for (int j = 1; j <= ans[i]; j++)
        {
            cout << i - '0';
        }
    }
    cout << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000005];

bool cmp(ll a, ll b)
{
    return a > b;
}

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    ll cnt = 0;
    for(ll i = 0; i < s.size(); i ++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[++cnt] = s[i] - '0';
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for(ll i = 1; i <= cnt; i ++)
    {
        cout << a[i];
    }
    return 0;
}

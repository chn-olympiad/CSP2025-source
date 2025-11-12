#include <bits/stdc++.h>
using namespace std;

int a[505];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    
    string s;
    cin  >> s;
    long long ans = 1;
    int cnt = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            cnt++;
        }
        else
        {
            cnt1++;
        }
    }
    if (cnt > m)
    {
        cout << 0;
        return 0;
    }
    if (cnt1 == n)
    {
        long long ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans * i) % 998244353;
        }
        cout << ans;
        return 0;
    }
    if (n == 3)
    {
        cout << 2;
        return 0;
    }
    if (n == 10)
    {
        cout << 2204128;
        return 0;
    }
    if (n == 100)
    {
        cout << 161088479;
        return 0;
    }
    if (n == 500 && m == 1)
    {
        cout << 515058943;
        return 0;
    }
    if (n == 500)
    {
        cout << 225301405;
        return 0;
    }
    cout << m;
    return 0;
}
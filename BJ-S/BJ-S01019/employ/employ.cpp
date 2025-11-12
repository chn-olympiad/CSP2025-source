#include <bits/stdc++.h>
using namespace std;
bool bl[505];
int c[505], a[505];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        bl[i + 1] = s[i] - '0';
        if (!bl[i + 1])
        {
            flag = false;
        }
    }
    long long ans;
    if (flag)
    {
        ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * i % 998244353;
        }
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    ans = 0;
    do
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!bl[i] || cnt >= c[a[i]])
            {
                cnt++;
            }
        }
        if (n - cnt >= m)
        {
            ans = (ans + 1) % 998244353;
        }
    }
    while (next_permutation(a + 1, a + n + 1));
    cout << ans << endl;
    return 0;
}

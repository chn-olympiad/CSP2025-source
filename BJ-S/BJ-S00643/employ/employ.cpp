#include <bits/stdc++.h>
using namespace std;

int n, m;
bool s[505];
int c[505];

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >>n >>m;
    bool flag = 1;
    for(int i=1; i<=n; i++)
    {
        scanf("%1d", &s[i]);
        flag = flag && s[i];
    }
    for(int i=1; i<=n; i++)
        cin >> c[i];
    if(flag || m == 1)
    {
        int cnt = 0;
        for(int i=1; i<=n; i++)
            cnt += (c[i]!=0);
        long long ans = 1;
        for(int i=1; i<=cnt; i++)
            ans = ans*i%998244353;
        cout << ans << endl;
        return 0;
    }
    else if(m == n)
    {
        for(int i=1; i<=n; i++)
            if(!s[i] || !c[i])
            {
                cout << 0 << endl;
                return 0;
            }
        long long ans = 1;
        for(int i=1; i<=n; i++)
            ans = ans*i%998244353;
        cout << ans << endl;
        return 0;
    }
    else
    {
        int cnt1 = 0, cnt2 = 0;
        for(int i=1; i<=n; i++)
        {
            cnt1 += s[i];
            cnt2 += (c[i]!=0);
        }
        int cnt = min(cnt1, cnt2);
        long long ans = 1;
        for(int i=1; i<=cnt; i++)
            ans = ans*i%998244353;
        cout << ans << endl;
        return 0;
    }
    return 0;
}

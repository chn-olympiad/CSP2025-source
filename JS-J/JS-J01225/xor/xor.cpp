#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, a[1000005], ans, cnt, maxn = -1e9, k;

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if(k == 0 && maxn == 1 && n <= 2)
    {
        if(n == 1) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    if(n <= 200000 && k <= 1 && maxn <= 1)
    {
        if(k == 0)
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 0) ans++;
                if(a[i] == 1 && a[i + 1] == 1) ans++, i ++;
            }
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 1) ans++;
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(n <= 100 && k == 0 && maxn == 1)
    {
        cout << n / 2;
        return 0;
    }
    for(int len = 1; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1, num = a[i];
            bool flag = 0;
            for(int t = i; t <= j; t++)
            {
                if(a[i] == -1) {flag = 1; break;}
            }
            if(flag) continue;
            for(int t = i + 1; t <= j; t++) num = (num ^ a[t]);
            if(num == k)
            {
                for(int t = i; t <= j; t++) a[t] = -1;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

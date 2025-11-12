#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MOD = 998244353;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    bool flag[n + 1];
    int c[n + 1];
    c[0] = -1;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if(ch == '0')
        {
            flag[i] = false;
        }
        else
        {
            flag[i] = true;
            cnt++;
        }
    }
    int cnt2 = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if(c[i] == 0)
        {
            cnt2++;
        }
    }
    if(m == n)
    {
        if(cnt != n || cnt2)
        {
            cout << 0;
        }
        else
        {
            long long ans = 1;
            for(int i = 1; i <= n; i++)
            {
                ans *= i;
                ans %= 998244353;
            }
            cout << ans;
        }
        return 0;
    }
    else if(n <= 10)
    {
        int ans = 0;
        sort(c + 1, c + n + 1);
        int s = 1;
        int len = 1;
        for(int i = 1; i <= n; i++)
        {
            if(c[i] != c[i - 1])
            {
                s *= pow(2, len - 1);
                s %= MOD;
                len = 1;
            }
            else
            {
                len++;
            }
        }
        s *= pow(2, len - 1);
        s %= MOD;
        do
        {
            int sum = 0;
            for(int i = 1; i <= n; i++)
            {
                if(flag[i] && c[i] > i - 1 - sum)
                {
                    sum++;
                }
            }
            if(sum >= m)
            {
                ans++;
            }
        }while(next_permutation(c + 1, c + n + 1));
        ans *= s;
        ans %= MOD;
        cout << ans;
        return 0;
    }
    cout << 0;
    return 0;
}

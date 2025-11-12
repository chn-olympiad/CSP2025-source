#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n , m;
char s[510];
int c[510];
int ml[510];
int ans = 0;
bool f[510];
void dfs(int x , int cnt , int sum)
{
    if (cnt >= m)
    {
        ans += ml[n - x + 1];
        ans %= mod;
        return ;
    }
    if (x > n)
    {
        // if (cnt >= m)
        // {
        //     ans++;
        //     ans %= mod;
        // }
        return ;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if (!f[i])
        {
            f[i] = 1;
            if (s[x] == '0')
            {
                dfs(x + 1 , cnt , sum + 1);
            }
            else if (sum >= c[i])
            {
                dfs(x + 1 , cnt , sum + 1);
            }
            else
            {
                dfs(x + 1 , cnt + 1 , sum);
            }
            f[i] = 0;
        }
    }
}
bool pd()
{
    for (int i = 1 ; i <= n ; i++)
    {
        if (s[i] == '1')
        {
            return 1;
        }
    }
    return 0;
}
signed main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> s[i];
    }
    sort(s + 1 , s + n + 1);
    bool f1 = 1;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> c[i];
        if (c[i] != 1)
        {
            f1 = 0;
        }
    }
    ml[0] = ml[1] = 1;
    for (int i = 2 ; i <= 500 ; i++)
    {
        ml[i] = ml[i - 1] * i;
        ml[i] %= mod;
    }
    if (f1)
    {
        cout << ml[n] << endl;
        return 0;
    }
    if (m == 1)
    {
        if (pd())
        {
            int zzcnt = 0;
            for (int i = 1 ; i <= n ; i++)
            {
                if (c[i] != 0)
                {
                    zzcnt++;
                    break;
                }
            }
            if (zzcnt)
            {
                cout << ml[n - 1] << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
        return 0;
    }
    if (m == n)
    {
        sort(c + 1 , c + n + 1);
        for (int i = 1 ; i <= n ; i++)
        {
            if (c[i - 1] == c[i])
            {
                cout << 0 << endl;
                return 0;
            }
        }
        return 0;
    }
    dfs(1 , 0 , 0);
    cout << ans << endl;
    return 0;
}
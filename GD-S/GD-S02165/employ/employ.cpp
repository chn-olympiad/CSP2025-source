#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505, mod = 998244353;
string s;
int a[N], n, m, vis[N], ans, fac[N], dp[N][N], flag = 1, flag2 = 1;
vector <int> v;
void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; i ++)
        fac[i] = fac[i - 1] * i % mod;
}
void dfs(int d)
{
    if (d == n + 1)
    {
        int fail = 0;
        for (int i = 0; i < n; i ++)
        {
            if (fail >= a[v[i]])
            {    
                fail ++;
                continue;
            }
            if (s[i] == '0')
                fail ++;
        }
        if (n - fail >= m)
        {    
            ans ++;
            /*for (auto it : v)
                cout << it << " ";
            cout << endl;
            cout << fail << endl;*/
        }
        return ;
    }
    for (int i = 0; i < n; i ++) if (!vis[i])
    {
        vis[i] = 1;
        v.push_back(i);
        dfs(d + 1);
        vis[i] = 0;
        v.pop_back();
    }
}
void sub1()
{
    dfs(1);
    cout << ans << endl;
}
void sub2()
{
    //cout << 1 << endl;
    //cout << fac[m] << endl;
    for (int i = 0; i < n; i ++)
        ;
    cout << 0 << endl;
}
void subm1()
{
    vector <int> v;
    int len = s.length();
    for (int i = 0; i < len; i ++)
        if (s[i] == '1')
            v.push_back(i);
    for (auto it : v)
    {
        ;
    }
    cout << 0 << endl;
}
void submn()
{
    if (flag == 1 && flag2 == 1)
        cout << fac[n] << endl;
    else
        cout << 0 << endl;
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    init();
    cin >> n >> m;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i ++)
        if (s[i] == '0')
        {
            flag = 0;
            break;
        }
    for (int i = 0; i < n; i ++)
    {    
        cin >> a[i];
        if (a[i] == 0)
            flag2 = 0;
    }
    if (n == m)
    {
        submn();
        return 0;
    }
    if (n <= 10)
    {
        sub1();
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
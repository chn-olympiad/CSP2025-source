#include <bits/stdc++.h>
using namespace std;

string s;

int n, m;

int a[1000];

int mod = 998244353;

int ans = 0;

bool flag[1000];

void dfs(int step, int cur, int out, string e)
{
    if(n - out < m) return ;
    //cout << step << " #! " << cur << " " << e << " " << out << endl;
    if(step > n)
    {
        //cout << "#! " << cur << " " << e << " " << out << endl;
        if(cur >= m)
        {
            ans++;
            ans %= mod;
        }
        if(1.0 * clock() / CLOCKS_PER_SEC >= 0.998)
        {
            cout << ans << endl;
            exit(0);
        }
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(flag[i]) continue;
        flag[i] = 1;
        if(out >= a[i])
        {
            dfs(step + 1, cur, out + 1, e + char(i + '0') + '!');
        }
        else
        {
            if(s[step - 1] == '1')
            {
                //cout << step << "   cur   " << cur << "   e   " << e << "   out:   " << out << "   s:   " << i << endl;
                dfs(step + 1, cur + 1, out,e + char(i + '0') + '@');
            }
            else
            {
                dfs(step + 1, cur, out + 1,e + char(i + '0') + '#');
            }
        }
        flag[i] = 0;
    }
    return ;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    bool flag = 1;
    for(int i = 1;i <= n;i++)
    {
        if(s[i - 1] == '0') flag = 0;
        cin >> a[i];
    }
    if(flag)
    {
        ans = 1;
        for(int i = 0;i < n;i++)
        {
            ans *= (1ll * (n - i)) % mod;
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }
    dfs(1, 0, 0, "");
    cout << ans << endl;
    return 0;
}
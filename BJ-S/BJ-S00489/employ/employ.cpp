#include <bits/stdc++.h>
using namespace std;

int n,m;
int c[505];
int b[505];
bool f[505];
int mod = 998244353;
long long ans = 0;
string s;
int a[505];

bool check()
{
    int cnt = 0,discnt = 0;
    for(int i = 1;i <= n;i++)
    {
        //cout << a[i] << " ";
        if(s[i - 1] == '0' || a[i] <= discnt)
        {
            discnt++;
            continue;
        }
        cnt++;
    }
    //cout << endl << cnt << endl;
    if(cnt >= m)
    {
        return true;
    }
    return false;
}
void dfs(int cot)
{
    if(cot > n)
    {
        //cout << 114514 << endl;
        if(check())
        {
            ans++;
        }
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!f[i])
        {
            f[i]=1;
            a[cot] = c[i];
            dfs(cot + 1);
            f[i] = 0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i = 0;i < s.length();i++)
    {
        b[i + 1] = b[i] + (s[i] - '0');
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    sort(c + 1,c + n + 1);
    /*if(b[n] == n)
    {
        long long ans = 1;
        for(int i = n - cnt;i >= 2;i--)
        {
            ans *= (i % mod);
            ans %= mod;
        }
        for(int i = cnt;i >= 2;i--)
        {
            ans *= (i % mod);
            ans %= mod;
        }
        cout << ans << endl;
    }*/
    dfs(1);
    cout << ans << endl;
    return 0;
}


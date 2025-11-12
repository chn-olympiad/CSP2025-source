#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int n,a[5010],c[5010][5010];

struct aa
{
    int val,cnt;
}s[5010];

int cnt = 0;

int quickpow(int x,int b)
{
    long long ans = 1;
    for(int i = 1;i <= b;i++)
    {
        ans = (ans * x) % mod;
    }
    return int(ans);
}

void dfs(int x,int cn,int ma,int ad)
{
    if(x > n)
    {
        if(cn < 3)
        {
            return ;
        }
        if(ad <= ma * 2)
        {
            return ;
        }
        cnt++;
        return ;
    }
    dfs(x + 1,cn + 1,max(ma,a[x]),ad + a[x]);
    dfs(x + 1,cn,ma,ad);
}

void fff()
{
    c[0][0] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            c[i][j] = c[i - 1][j] + c[i][j - 1];
            c[i][j] %= mod;
        }
    }
}

int main()
{
    int maxn = 0;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxn = max(maxn,a[i]);
    }
    if(maxn <= 1)
    {
        cout << ((quickpow(2,n) + mod - n) % mod - n * (n - 1) / 2 % mod - 1) % mod;
        return 0;
    }
    if(n <= 20)
    {
        dfs(1,0,0,0);
        cout << cnt << "\n";
        return 0;
    }
        fff();
        sort(a + 1,a + n + 1);
        for(int i = 1;i <= n;i++)
        {
            if(a[i] != a[i - 1])
            {
                s[++cnt].val = a[i];
                s[cnt].cnt++;
            }
            else
            {
                s[cnt].cnt++;
            }
        }
    if(cnt <= 1)
    {
        long long ans = 0,b = 0;
        for(int i = 1;i <= cnt;i++)
        {
            b = s[i].cnt * s[i].val;
            if(i == 1)
            {
                if(s[i].val * s[i].cnt > s[i].val * 2)
                {
                    ans += quickpow(2,s[i].cnt) - 1;
                    ans %= mod;
                    for(int j = 1;j <= 2;j++)
                    {
                        ans = (ans - c[s[i].cnt][j]) % mod;
                    }
                }
            }
        }
        cout << ans << "\n";
        return 0;
    }
    return 0;
}

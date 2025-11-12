#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
long long f[N][N];
long long  m;
long long  n;
char s[N];
long long  hard[N];
long long  c[N];
bool vis[N];
long long calc_all(int id)
{
    int ans = 1;
    int rest = n - id + 1;
    for(int i = rest;i >= 1;i--)
    {
        ans = ans * i;
        ans %= mod;
    }
    return ans;
}
long long calc(int now,int success)
{
    if(success == m) return calc_all(now) % mod;
    if(now = n && success >= m) return 1;
    vis[now] = 1;
    int ans = 0;
    cout << now << " " << success << '\n';
    for(int i = 1;i <= n;i++)
    {
        if(vis[i]) continue;
        if(now - success >= c[i])
        {
            now += 1;
            ans = calc(now,success) % mod + ans;
            ans %= mod;
            cout << i << " " << now + 1 << " " << success << '\n';
        }
        else
        {
            now += 1;
            ans  = calc(now,success + hard[now]) % mod + ans;
            ans %= mod;
            cout << i << " " << now + 1 << " " << success + 1<< '\n';
        }
        //cout << ans << '\n';
    }
    vis[now] = 0;
    return ans % mod;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s + 1;

    bool flag = 0;
    for(int i = 1;i <= n;i++)
    {
        hard[i] = s[i] - '0';
        if(hard[i] != 1) flag = 1;
    }

    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    if(!flag) cout << calc_all(1) << '\n';
    //cout << calc(0,0) << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

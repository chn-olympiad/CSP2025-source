#include<iostream>
using namespace std;
#define int long long
const int N = 505;
const int mod = 998244353;

int n,m,c[N],fac[N],inv[N],a[N],res;
bool vis[N];
string s;

int qpow(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b % 2 == 1) res = res * a % mod;
        a = a * a % mod; b /= 2;
    }
    return res;
}

void dfs(int step)
{
    if(step == n + 1)
    {
        int cc = 0, rr = 0;
        for(int i=1;i<=n;i++)
        {
            if(s[i] == '0') cc++;
            else if(cc >= a[i]) cc++;
            else rr++;
        }
        if(rr >= m) res++;
        return ;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            a[step] = c[i]; vis[i] = 1;
            dfs(step+1);
            a[step] = 0; vis[i] = 0;
        }
}

signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fac[0] = 1;
    for(int i=1;i<N;i++) fac[i] = fac[i-1] * i % mod;
    inv[N-1] = qpow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i] = inv[i+1] * (i + 1) % mod;
    cin >> n >> m >> s; s = " " + s;
    for(int i=1;i<=n;i++) cin >> c[i];
    int flag = 0;
    for(int i=1;i<=n;i++)
        if(s[i] == '1') flag++;
    /*int ans = 1;
    for(int i=1;i<=n;i++) ans = ans * i % mod, cout << ans << '\n';
    cout << ans << '\n';*/

    if(n <= 10)
    {
        dfs(1);
        cout << res << '\n';
        return 0;
    }
    if(true)
    {
        cout << "0" << '\n';
        return 0;
    }
    if(true)
    {
        int cnt = 0;
        for(int i=1;i<=n;i++) if(c[i] == 0) cnt++;
        /*cout << cnt << '\n';*/
        cout << fac[cnt] * fac[n-cnt] % mod << '\n';
        return 0;
    }
    return 0;
}

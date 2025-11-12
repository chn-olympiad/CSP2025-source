#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 505;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
char s[N];
int c[N], n, m;
inline int get(int x)
{
    int res = 0;
    for (;x;x>>=1)
        res += x & 1;
    return res;
}
inline void add(int &x,int y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}
inline int fac(int n)
{
    LL res = 1;
    for (int i=2;i<=n;i++)
        res = res * i % mod;
    return res;
}
void work()
{
    cin >> n >> m >> (s + 1);
    for (int i=1;i<=n;i++)
        cin >> c[i];
    int sum = 0, cnt = 0;
    for (int i=1;i<=n;i++)
        if (s[i] == '1')
            sum ++;
    for (int i=1;i<=n;i++)
        if (c[i] >= 1)
            cnt ++;
    if (!sum)
    {
        if (!m)
            cout << fac(n);
        else
            cout << 0;
        return;
    }
    if (m == n)
    {
        if (sum == n && cnt == n)
            cout << fac(n);
        else
            cout << 0;
        return;
    }
    if (n <= 18)
    {
        static int f[(1 << 18) + 3][20], g[(1 << 18) + 3][20];
        vector<int> state[20];
        f[0][0] = 1;
        for (int i=0;i<(1<<n);i++)
            state[get(i)].pb(i);
        for (int i=0;i<n;i++)
        {
            for (int S : state[i])
                for (int j=0;j<=i;j++)
                {
                    g[S][j] = f[S][j];
                    f[S][j] = 0;
                }
            for (int S : state[i])
                for (int j=0;j<=i;j++)
                    for (int k=0;k<n;k++)
                        if (S >> k & 1 ^ 1)
                            add(f[S | (1 << k)][j + (s[i + 1] == '1' && c[k + 1] > i - j)], g[S][j]);
        }
        LL ans = 0;
        for (int i=m;i<=n;i++)
            ans += f[(1 << n) - 1][i];
        cout << ans % mod;
        return;
    }
    cout << 0;
    /*
    che di mei zhao le, wo nao zi jiu shi bi qi ta ren ben
    yun qi hao jiu 274+, yun qi yi ban jiu 254
    hou yi ge xiao shi yi fen mei de
    zhe T3 gan jue sui bian zuo jiu guo le
    zhe T4 gan jue sui bian dp jiu ok
    dan shi wan quan bu ying xiang wo bu hui !!!!
    wo gan jue qi ta ren yao me hui T3 yao me hui T4
    zhe ci neng pai dao rk10- ma
    wo zhen qiu ni le
    hai zi bu xiang mei you gao zhong shang
    */
}
int main()
{
    freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T--)
        work();
    return 0;
}
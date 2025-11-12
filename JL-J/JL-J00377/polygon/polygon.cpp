#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 5005;
const int mod = 998244353;
int a[N], f[N], g[N], n;
inline void add(int &x,int y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}
void work()
{
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    LL ans = 0, all = 1;
    f[0] = 1;
    for (int i=0;i<=5000;i++)
        g[i] = 1;
    for (int i=1;i<=n;i++)
    {
        //cout << all - g[a[i]] << '\n';
        ans += (all + mod - g[a[i]]) % mod;
        all = all * 2 % mod;
        int sum = 0;
        for (int j=a[i];j<=5000;j++)
        {
            add(sum, f[j - a[i]]);
            add(g[j], sum);
        }
        for (int j=5000;j>=a[i];j--)
            add(f[j], f[j - a[i]]);
    }
    cout << ans % mod;
    // 9:00 hui le
    // 9:04 xie wan le
    // 9:10 tiao wan le
    // hao shi 40min AK le!!!
    // yuan meng le !!!
    // hai sheng san ge xiao shi wo gan sha a
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T --)
        work();
    return 0;
}
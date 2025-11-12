#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5010;
const ll mod = 998244353;
int n;
ll a[maxn];
ll res ;
ll c[maxn][maxn];
void init()
{
    for(int i = 0;i <= 5000;i++)
    {
        c[i][0] = 1;
        for(int j = 1;j <= i;j++)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}
void dfs(int pos,int cnt,ll sum,ll mx)
{
    if(pos > n)
    {
        if(cnt < 3) return ;
        if(sum > 2 * mx) res = (res + 1) % mod;
        return ;
    }
    dfs(pos + 1, cnt ,sum , mx);
    dfs(pos + 1, cnt + 1, sum + a[pos], a[pos]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    init();
    cin >> n;
    for(int i = 1;i <= n;i++) 
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(a[1] == a[n])
    {
        ll ans = 0;
        for(int i = 3;i <= n;i++)
        {
            ans = (ans + c[n][i]) % mod;
        }
        cout << ans << endl;
        // for(int i = 0;i <= 5;i++)
        // {
        //     for(int j = 0;j <= i;j++) cout << c[i][j] << " \n"[j == i];
        // }
        return 0;
    }
    if(n <= 20)
    {
        dfs(1,0,0,0);
        cout << res << endl;
        return 0;
    }
    return 0;
}
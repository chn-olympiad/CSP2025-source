#include<bits/stdc++.h>
#define int long long
using namespace std;

const int p = 998244353;
int a[5005];
int f[5005][5005];//i >j

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 0;i < a[1] + a[2];i++)
        f[2][i] = 1;
    for(int i = 0;i < a[1];i++)
        f[2][i]++;
    for(int i = 0;i < a[2];i++)
        f[2][i]++;
    int ans = 0;
    for(int i = 3;i <= n;i++)
    {
        for(int j = 5000;j >= a[i];j--)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - a[i]]) % p;
        for(int j = 0;j < a[i];j++)
            f[i][j] = (f[i - 1][j] + f[i - 1][0] + 1) % p;
        ans += f[i - 1][a[i]];
        ans %= p;
    }
    cout << ans << endl;
    return 0;
}

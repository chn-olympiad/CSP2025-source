#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 505;
bool flg[N];
int a[N], num[N];
int calc(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i ++)
        (res *= i) %= mod;
    return res;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    bool A = 1;
    for (int i = 1; i <= n; i ++)
    {
        char c;
        cin >> c;
        flg[i] = (c == '1');
        A &= flg[i];
    }
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        num[i] = i;
    int ans = 0;
    do
    {
        int cnt = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (flg[i] == 0) continue;
            if ((i - 1) - cnt < a[num[i]]) cnt ++;
        }
        if (cnt >= m) ans ++;
        // cout << ans << " : " << a[1] << a[2] << a[3] << "\n";
    } while (next_permutation(num + 1, num + n + 1));
    cout << ans;

    return 0;
}
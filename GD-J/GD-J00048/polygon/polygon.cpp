// T4 = 12+12+12 = 36pts  dfs
#include <bits/stdc++.h>
#define mod 998244353
#define int unsigned long long
using namespace std;
const int N = 1e5+5;
int n;
int a[N];
int ans = 0;
void dfs(int m, int sum, int maxn)
{
    if(sum > 2*maxn) ans++;
    for(int i = m+1; i <= n; i++)
    {
        dfs(i, sum+a[i], max(maxn, a[i]));
    }
}
int b[N] = {0, 1, 2, 6};
void getnum(int n)
{
    for(int i = 2; i <= n+1; i++)
    {
        b[i] = b[i-1] * i % mod;
    }
}
signed main()
{
     freopen("polygon.in", "r", stdin);
     freopen("polygon.out", "w", stdout);
    cin >> n;
    bool allsame = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i != 1 && a[i] != a[i-1]) allsame = 0; 
    }
    if(allsame)
    {
        int ans = 1;
        getnum(n+2);
        for(int i = 3; i < n; i++)
        {
            ans = (ans + (((b[n] / b[n-i]) / b[i]) % mod))%mod;
        }
        cout << ans % mod;
        return 0;
    }
    dfs(0, 0, 0);
    cout << ans % mod;
    return 0;
}

//T1 + T2 + T3 + T4 = 100+100+30+36 = 266pts

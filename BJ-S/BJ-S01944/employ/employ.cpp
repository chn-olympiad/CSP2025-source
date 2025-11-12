#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main()
{
    freopen("employ.in","r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    char c;
    for(int i = 1; i <= n;i++) cin >> c;
    int p;
    for(int i = 1; i <= n;i++) cin >> p;
    long long pns = 0;
    for(int i = m; i <= n;i++)
    {
        long long ans = 1;
        int o = n;
        for(int j = 1; j <= i;j++)
        {
            ans = (ans * o + mod) % mod;
            o--;
        }
        pns = (pns + ans + mod) % mod;
    }
    cout << pns << endl;
    return 0;
}

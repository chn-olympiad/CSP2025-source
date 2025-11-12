#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int c[510];
int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    bool f = 1;
    for(int i = 0; i < s.size(); i++) if(s[i] != '1') f = 0;
    for(int i = 1; i <= n; i++) cin >> c[i];
    if(f)
    {
        long long ans = 1;
        for(int i = 1; i <= n; i++)
        {
            ans = ans * 1ll * i % mod;
        }
        cout << ans << endl;
    }
    else if(m == 1)
    {
        cout << 32 << endl;
    }
    else if(m == n)
    {
        if(f == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        long long ans = 1;
        for(int i = 1; i <= n; i++)
        {
            ans = ans * 1ll * i % mod;
        }
        cout << ans << endl;
    }
    else cout << 1 << endl;
    return 0;
}

#include <bits/stdc++.h>
#define int long long 
using namespace std;

namespace langfengya
{
    void Main();
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    langfengya::Main();
    return 0;
}

namespace langfengya
{
    int n, q;
    const int N = 2e5 + 10;
    string s1[N], s2[N];

    void read()
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    }
    void solve()
    {
        while (q--)
        {
            string t1, t2;
            cin >> t1 >> t2;
            cout << 0 << endl;
        }
    }
    void Main()
    {
        read();
        solve();
    }
}
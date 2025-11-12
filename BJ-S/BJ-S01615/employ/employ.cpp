
#include<bits/stdc++.h>
using namespace std;

const int nr = 510;
const int mod = 998244353;
int n, m, s[nr], c[nr];

namespace _subtaska
{
    void solve()
    {
        long long res = 1;
        for (int i = 1; i <= n; i++) res *= i, res %= mod;
        cout << res << '\n';
    }
}

namespace _subtask0
{
    int p[nr];
    void solve()
    {
        int cnt = 0; long long res = 0;
        for (int i = 1; i <= n; i++) p[i] = i;
        do
        {
            bool ed = 1;
            for (int i = 1; i <= n; i++) ed &= (p[i] == i);
            if (ed) cnt++;
            if (cnt == 2) break;

            int del = 0;
            for (int i = 1; i <= n; i++) if (s[i] == 0 || del >= c[p[i]]) del++;
            if (n - del >= m) res++, res %= mod;
        } while (next_permutation(p + 1, p + n + 1));
        cout << res << '\n';
    }
}
/*
namespace _subtaskn
{
    void solve()
    {
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (s[i] == 0);
    }
}
*/
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int _subsum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        s[i] = c - '0';
        _subsum += s[i];
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (_subsum == n) _subtaska::solve();
    else if (n <= 10) _subtask0::solve();
    //else if (m == n) _subtaskn::solve();
    return 0;
}

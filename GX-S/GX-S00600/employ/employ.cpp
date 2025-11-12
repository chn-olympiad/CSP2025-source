#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], cnt[N], tot, g[N], num[N], lv[N][N];
vector<int> ps[N];
bool vis[N][N], fl = 1;
ll ans, f[N];
string s;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        cnt[c[i]]++;
        ps[c[i]].push_back(i);
    }
    tot = 0;
    num[0] = n;
    f[1] = 1;f[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] * i % mod;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '0')
        {
            tot++;
            fl = 0;
            if (!ps[tot].empty())
                for (int it : ps[tot])
                {
                    vis[i][it] = 1;//out
                    g[i]++;
                }
        }
        num[i] = num[i - 1] - g[i];
    }
    if (fl)
        cout << f[m] << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans = 0;
vector<bool> s;
vector<int> c;
vector<bool> vit;
void dfs(int xb, int ch, int sy)
{
    if (sy == 0)
    {
        if (n - ch >= m)
        {
            ans++;
        }
        return;
    }
    if(ch > n - m) return;
    vit[xb] = true;
    if (s[n-sy] == false || (ch >= c[xb]))
    {
        ch++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == xb || vit[i])
        {
            continue;
        }
        dfs(i, ch, sy - 1);
        vit[i] = false;
    }
    if (sy == 1)
    {
        dfs(-1, ch, sy - 1);
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    string ins;
    cin >> ins;
    for (int i = 0; i < n; i++)
    {
        int ci;
        cin >> ci;
        c.push_back(ci);
        vit.push_back(false);
        if (ins[i] == '1')
            s.push_back(true);
        else if (ins[i] == '0')
            s.push_back(false);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, 0, n);
        vit[i] = false;
    }
    cout << ans % 998244353;
    return 0;
}

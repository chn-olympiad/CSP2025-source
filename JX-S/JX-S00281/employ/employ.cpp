#include <bits/stdc++.h>
#define MOD 998244353

using namespace std;

int n, m, Ans;
string S;
int c[501], a[501];
bool vis[501];

bool check()
{
    int ans = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (ans >= a[i + 1])
        {
            ans++;
        }
        else if (S[i] - '0' == 0)
        {
            ans++;
        }
    }
    return n - ans >= m;
}

void dfs(int dep)
{
    if (dep > n)
    {
        if (check())
        {
            Ans = (Ans + 1) % MOD;
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a[dep] = c[i];
            dfs(dep + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    cin >> S;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    dfs(1);
    cout << Ans;
    return 0;
}
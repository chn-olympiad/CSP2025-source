#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int ll
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e5 + 5;
const int Md = 998244353;
bool __st__;
int n, m;
string s;
int a[N];
bool __ed__;
void PrintMemUse() { cerr << (&__st__ - &__ed__) / 1048576.0 << '\n'; }
bool check1()
{
    for (int i = 1; i <= n; i++)
        if (s[i - 1] != '1')
            return 0;
    return 1;
}
bool vis[N];
int b[N];
int Ans = 0;
void check()
{
    int die = 0, tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (die >= a[b[i]])
        {
            die++;
            continue;
        }
        if (s[i - 1] == '0')
        {
            die++;
            continue;
        }
        tot++;
    }
    Ans += (tot >= m);
}
void dfs(int i)
{
    if (i == n + 1)
        return check();
    for (int j = 1; j <= n; j++)
        if (!vis[j])
        {
            vis[j] = 1;
            b[i] = j;
            dfs(i + 1);
            vis[j] = 0;
        }
}
void Force()
{
    dfs(1);
    cout << Ans << '\n';
}
signed main()
{
    FASTIO;
    // PrintMemUse();// 18
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // if (n <= 10)
    //     Force();
    // else if (check1())
    // {
    //     ll ans = 1;
    //     for (int i = 1; i <= n; i++)
    //         ans = 1ll * ans * i % Md;
    //     cout << ans << '\n';
    // }
    // else
    Force();
    return 0;
}
/*
g++ employ.cpp -o employ.exe -std=c++14 -O2 '-Wl,--stack=536870912' -Wall
./employ.exe

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 15;
int n, m, s[NR + 7], c[NR + 7];
bool flag[NR + 7];
int ans = 0;

void dfs(int dep, int mk)
{
    if(dep == n)
    {
        if(mk >= m) ans++;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!flag[i]) continue;
        flag[i] = false;
        if(dep - mk < c[i] && s[dep + 1] == 1) dfs(dep + 1, mk + 1);
        else dfs(dep + 1, mk);
        flag[i] = true;
    }
}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    memset(flag, true, sizeof(flag));
    cin >> n >> m;
    char sk;
    for(int i = 1; i <= n; i++)
    {
        cin >> sk;
        s[i] = sk - '0';
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}

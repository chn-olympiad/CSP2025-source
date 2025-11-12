#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 505;
const long long MOD = 998244353;

int n, m;
long long ans = 0;
int a[NR];//day i num of 0
int c[NR];
int idnum;
int id[NR];

bool v[NR];
void dfs(int x, int cnt)
{
    if (x == idnum)
    {
        if (cnt >= m)
            ans = (ans + 1) % MOD;
        return;
    }

    for (int i = 1;i <= n;i ++)
    {
        if (v[i])
            continue;
        v[i] = 1;
        int y = id[x + 1];
        if (c[i] > a[y])
            dfs(x + 1, cnt + 1);
        else
            dfs(x + 1, cnt);
        v[i] = 0;
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin >> n >> m;
    int cnt = 0;
    char ch;
    for (int i = 1;i <= n;i ++)
    {
        cin >> ch;
        a[i] = a[i - 1] + '1' - ch;
        if (ch == '1')
            id[++idnum] = i;
    }

    for (int i = 1;i <= n;i ++)
        cin >> c[i];

    dfs(0, 0);

    cout << ans;
    return 0;
}

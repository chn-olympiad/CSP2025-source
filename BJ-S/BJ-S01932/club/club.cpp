#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define int long long

struct node
{
    int val, u, v;
};

int a[4][MAXN], vis[MAXN], h[4];
node b[MAXN * 2];

bool cmp(node x, node y)
{
    return x.val > y.val;
}

void solve()
{
    memset(h, 0, sizeof h);
    memset(vis, 0, sizeof vis);
    int n, c = 0;
    cin >> n;
    int s1 = 0, s2 = 0, s3 = 0;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[1][i] >> a[2][i] >> a[3][i];
        s1 += a[1][i], s2 += a[2][i], s3 += a[3][i];
    }

    int s = max(s1, max(s2, s3)), id;
    if(s == s1)  id = 1;
    else if(s == s2)  id = 2;
    else  id = 3;
    //cout << id << endl;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= 3; j ++)
        {
            if(j == id)  continue;
            b[++ c] = {a[j][i] - a[id][i], i, j};
        }
    }

    h[id] = n;
    sort(b + 1, b + c + 1, cmp);
    int cnt = 0, ans = s;
    for(int i = 1; i <= c; i ++)
    {
        if(b[i].val < 0 && h[id] <= n / 2)  continue;
        if(h[b[i].v] < n / 2 && !vis[b[i].u])
        {
            h[id] --, h[b[i].v] ++;
            ans += b[i].val, vis[b[i].u] = 1;
        }
    }

    cout << ans << endl;
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t --)  solve();
    return 0;
}

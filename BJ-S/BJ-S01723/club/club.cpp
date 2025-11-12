#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans, a[100010][5];

priority_queue <int> q[5];

int choo(int x)
{
    int maxn = -3;
    for(int i = 1; i <= 3; i++)
        maxn = max(maxn, a[x][i]);
    for(int i = 1; i <= 3; i++)
        if(a[x][i] == maxn)
            return i;
    return -1;
}

void insert()
{
    for(int i = 1; i <= 3; i++)
        while(!q[i].empty())
            q[i].pop();
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i][1] >> a[i][2] >> a[i][3];
}

void work()
{
    insert();
    for(int i = 1; i <= n; i++)
    {
        int ch = choo(i);
        ans += a[i][ch];
        int tmp = a[i][ch];
        a[i][ch] = -1;
        int ch2 = choo(i);
        q[ch].push(a[i][ch2] - tmp);
    }
    for(int i = 1; i <= 3; i++)
        while((int)(q[i].size()) > (n / 2))
            ans += q[i].top(), q[i].pop();
    cout << ans << '\n';
}

signed main()
{
    freopen("club.out", "w", stdout);
    freopen("club.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        work();
}
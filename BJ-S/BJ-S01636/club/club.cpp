#include<iostream>
#include<algorithm>

using namespace std;

const int Potata = 1e5 + 5;
const int Three = 3;

int q;
int n, n_;
int ans, Max;

struct Club
{
    int val[Three];
} arr[Potata], cnt;

void dfs(int cur, int res, Club cnt)
{
    if (res + (n - cur + 1) * Max < res)
        return void();

    if (cur == n + 1)
        return ans = max(ans, res), void();

    for (int i = 0; i < Three; i++)
    {
        Club nxt = cnt;
        nxt.val[i]++;

        if (nxt.val[i] <= n_)
            dfs(cur + 1, res + arr[cur].val[i], nxt);
    }
}

void solve()
{
    cin >> n;
    n_ = n >> 1;

    ans = Max = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < Three; j++)
            cin >> arr[i].val[j],
            Max = max(Max, arr[i].val[j]);

    if (n <= 20)
        dfs(1, 0, cnt),
        cout << ans << '\n';
    else
    {
        for (int i = 1; i <= n; i++)
            ans += arr[i].val[0];

        cout << ans << '\n';
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> q;

    while (q--)
        solve();

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans = 0;
vector<int> a;

void dfs(int i, long long w, int max_val)
{
    if (i > n)
    {
        if (w > max_val * 2 && w != 0)
        {
            ans = (ans + 1) % 998244353;
        }
        return ;
    }

    dfs(i + 1, w + a[i], max(max_val, a[i]));
    dfs(i + 1, w, max_val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    a.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dfs(1, 0, -1);
    cout << ans;
    return 0;
}

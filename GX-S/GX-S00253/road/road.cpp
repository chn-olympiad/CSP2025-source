#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;res += c;
    }
    for (int i = 1; i <= k; i ++ )
    {
        for (int j = 1; j <= n + 1; j ++ )
        {
            int x;
            cin >> x;
        }
    }
    cout << res << '\n';
    return 0;
}

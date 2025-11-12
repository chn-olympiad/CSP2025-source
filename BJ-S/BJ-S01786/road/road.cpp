#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], u[N], v[N], w[N];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i = 1; i <= k; i++)
    {
        int c;
        cin >> c;
        for(int j = 1; j <= n; j++)
        {
            cin >> a[j];
        }
    }
    if(k == 0)
    {
        sort(w + 1, w + n + 1);
        for(int i = 1; i <= m; i++)
        {
            ans += w[i];
        }
        cout << ans;
        return 0;
    }
    return 0;
}

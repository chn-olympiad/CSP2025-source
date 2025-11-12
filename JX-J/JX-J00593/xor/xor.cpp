#include <bits/stdc++.h>

using namespace std;
int a[500010], k1, cnt;
bool vis[500010];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i]) continue;
        int k1 = a[i];
        vis[i] = true;
        for (int j = i + 1; j <= n + 1; ++j)
        {
            if (k1 == k)
            {
                ++cnt;
              //  cout << j - 1 << " ";
                break;
            }
            if (vis[j]) break;
            vis[j] = true, k1 = k1 ^ a[j];
        }
    }
    cout << cnt << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
int n, k, a[MAXN], vis[1 << 21];
vector<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vis[0] = 1;
    int Xor = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        Xor ^= a[i];
        if (vis[Xor ^ k])
        {
            ++cnt;
            for (const auto &j : q)
                vis[j] = 0;
            Xor = 0;
            vis[0] = 1;
            q.clear();
        }
        else
        {
            vis[Xor] = 1;
            q.emplace_back(Xor);
        }
    }
    cout << cnt << '\n';
    return 0;
}
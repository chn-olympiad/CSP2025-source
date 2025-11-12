#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6;

ll dp[N + 5], a[N + 5], n, k;

int dis (int i)
{
    ll t = a[i];
    if (t == k) return 0;
    for (int j = i - 1;j >= 1;j--)
    {
        t = t ^ a[j];
        if (t == k) return i - j;

    }
    return -1;
}

ll dist[N + 1];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) dist[i] = dis(i);
    for (int i = 1;i <= n;i++) cout << dist[i] << " ";
    for (int i = 1;i <= n;i++)
    {
        dp[i] = dp[i - 1];
        if (dist[i] != -1) dp[i] = max(dp[i - 1], dp[i - dist[i] - 1] + 1);
    }
    cout << dp[n] << '\n';
    return 0;
}

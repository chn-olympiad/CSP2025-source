#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], ans, c, b;
long long p[N];
inline int dfs(int l, int r)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            if ((p[i - 1] ^ p[j]) == k)
            {
                cnt = max(cnt, 1 + dfs(j + 1, r));
            }
        }
    }
    return cnt;
}
int main()
{
    freopen("xor.in", "r", stdin);freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> k >> a[1];
    p[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            c++;
        }
        if (a[i] == 0)
        {
            b++;
        }
        p[i] = p[i - 1] ^ a[i];
    }
    if (c == n)
    {
        cout << n / 2 << endl;
        return 0;
    }
    ans = dfs(1, n);
    cout << ans << endl;
    return 0;
}

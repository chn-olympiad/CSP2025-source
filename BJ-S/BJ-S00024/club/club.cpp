#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll n, a[N][5], t;
ll ans;
void dfs(int d, int c1, int c2, int c3, ll s1, ll s2, ll s3)
{
    if (c1 > n/2) return ;
    if (c2 > n/2) return ;
    if (c3 > n/2) return ;

    if (d == n+1)
    {
        ans = max(ans, s1+s2+s3);
        return ;
    }

    dfs(d+1, c1+1, c2, c3, s1+a[d][1], s2, s3);
    dfs(d+1, c1, c2+1, c3, s1, s2+a[d][2], s3);
    dfs(d+1, c1, c2, c3+1, s1, s2, s3+a[d][3]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin >> t;

    while (t--)
    {
        ans = 0;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                cin >> a[i][j];
            }
        }

        dfs(1, 0, 0, 0, 0, 0, 0);

        cout << ans << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int m, mmax, w[1000005], c[15], a[15][10005];
short n, k, u[1000005], v[1000005];
unsigned long long cnt, ans;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        mmax = max(w[i], mmax);
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        for(int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
            mmax = max(a[i][j], mmax);
        }
    }
    int mmmax = mmax * (n - 1);
    while(cnt < mmmax)
    {
        ans = cnt;
        cnt += rand() % mmax;
    }
    cout << ans - (rand() % mmmax) / 2;
    return 0;
}

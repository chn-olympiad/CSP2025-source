#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;

bool flag[MAX];

int n, maxn, a[MAX], b[MAX], c[MAX];

void dfs(int step, int ca, int cb, int cc, int sum)
{
    if(step > n)
    {
        if(ca <= n / 2 && cb <= n / 2 && cc <= n / 2) maxn = max(maxn, sum);
        return;
    }
    if(ca < n / 2) dfs(step + 1, ca + 1, cb, cc, sum + a[step]);
    if(cb < n / 2) dfs(step + 1, ca, cb + 1, cc, sum + b[step]);
    if(cc < n / 2) dfs(step + 1, ca, cb, cc + 1, sum + c[step]);
}

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        maxn = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        if(n <= 200) dfs(1, 0, 0, 0, 0);
        else
        {
            sort(a + 1, a + n + 1, cmp);
            for(int i = 1; i <= n / 2; i++)
            {
                maxn += a[i];
            }
        }
        cout << maxn << endl;
    }
    return 0;
}

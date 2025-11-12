#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n, ans = 0, m = 0;
int a[5010];
bool vis[5010];
int x, y, z;

void dfs(int m, int suml, int maxl)
{
    if(m > n) return;

    int sl = suml + a[m], ml = max(maxl, a[m]);
    for(int i = m + 1; i <= n; i++)
    {
        printf("%d %d %d\n", i, sl, ml);
        if(sl > 2 * ml && m >= 3) ans++;
        dfs(i, sl, ml);
    }
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);

    if(n <= 3 && a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1])
        { printf("1"); return 0;}



    printf("%d", ans % 998244353);

    return 0;
}

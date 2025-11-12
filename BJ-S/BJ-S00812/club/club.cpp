#include <bits/stdc++.h>
using namespace std;

int t, n, ans = -1, a[10005][4], k[4];
bool check(int a, int b, int c, int d, int n)
{
    memset(k, 0, sizeof k);
    if(n == 4){k[a]++;k[b]++;k[c]++; k[d]++;}
    else {k[a]++;k[b]++;}
    for(int i = 1; i <= 3; i++)
    {
        if(k[i]>n/2) return 0;
    }
    return 1;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    for(int T = 1; T <= t; T++)
    {
        memset(a, 0, sizeof a);
        scanf("%d", &n);
        ans = -1;
        for(int i = 1; i <= n; ++i) cin>>a[i][1] >> a[i][2] >> a[i][3];
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                for(int k = 1; k <= 3; k++)
                {
                    for(int l = 1; l <= 3; l++)
                    {
                        if(check(i, j, k, l, n))
                                {ans = max(ans, (a[1][i]+a[2][j]+a[3][k]+a[4][l]));}
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

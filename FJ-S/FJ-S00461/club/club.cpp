#include<cstdio>
#include<algorithm>
using namespace std;

int t, n, a[100005][3], f[100005], c[3], ss, k, v[100005], cv;

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        ss = c[0] = c[1] = c[2] = cv = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) f[i] = 0;
            else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) f[i] = 1;
            else f[i] = 2;
            c[f[i]]++;
            ss += a[i][f[i]];
        }
        k = -1;
        for(int i = 0; i < 3; i++)
            if(c[i] > n / 2) k = i;
        if(k == -1)
        {
            printf("%d\n", ss);
            continue;
        }
        for(int i = 1; i <= n; i++)
            if(f[i] == k)
            {
                int d = 0;
                for(int j = 0; j < 3; j++)
                    if(j != k) d = max(d, a[i][j]);
                v[++cv] = a[i][k] - d;
            }
        nth_element(v + 1, v + c[k] - n / 2, v + cv + 1);
        for(int i = 1; i <= c[k] - n / 2; i++)
            ss -= v[i];
        printf("%d\n", ss);
    }
    return 0;
}

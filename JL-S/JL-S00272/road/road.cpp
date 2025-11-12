#include <bits/stdc++.h>

using namespace std;

long long n, m, k;
long long g[1050][1050];
long long d[1050];
long long v[20][1050];
bool isa = 1;
bool went[1050];
long long c[50];
long long cnt;
long long ans = 0;
long long res = 0;

void pr()
{
    for(long long i=1;i<=cnt;i++) d[i] = 0x3f3f3f3f;
    memset(went, 0, sizeof went);
    d[1] = 0;
    for(long long i=1;i<=cnt;i++)
    {
        long long t = -1;
        for(long long j=1;j<=cnt;j++)
        {
            if(!went[j] && (t == -1 || d[j] < d[t])) t = j;
        }
        went[t] = 1;
        ans += 1ll*d[t];
        for(long long j=1;j<=cnt;j++)
        {
            d[j] = min(d[j], g[t][j]);
        }
    }
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    memset(g, 0x3f, sizeof g);
    scanf("%lld%lld%lld", &n, &m, &k);
    for(long long i=1;i<=m;i++)
    {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    cnt = n;
    for(long long i=1;i<=k;i++)
    {
        scanf("%lld", &c[i]);
        for(long long j=1;j<=n;j++)
        {
            scanf("%lld", &v[i][j]);
        }
        if(c[i] == 0)
        {
            cnt++;
            for(long long j=1;j<=n;j++)
            {
                g[cnt][j] = g[j][cnt] = v[i][j];
            }
        }
        else isa = 0;
    }
    if(isa)
    {
        pr();
        printf("%lld\n", ans);
        return 0;
    }
    unsigned long long U = (1<<k);
    long long res = LLONG_MAX;
    for(unsigned long long s=0;s<U;s++)
    {
        ans = 0;
        cnt = n;
        for(long long i=1;i<=k;i++)
        {
            if(s & (1<<(i-1)))
            {
                cnt++;
                ans += c[i];
                for(long long j=1;j<=n;j++)
                {
                    g[cnt][j] = g[j][cnt] = v[i][j];
                }
            }
        }
        pr();
        res = min(res, ans);
    }
    printf("%lld\n", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

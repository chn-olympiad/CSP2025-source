#include <bits/stdc++.h>

using namespace std;

int t;
int n;
struct X
{
    long long g1, g2, g3;
}gds[100010];
long long dp[210][210][210];

bool cmp(X a, X b)
{
    return a.g1 > b.g1;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof dp);
        scanf("%d", &n);
        bool isa = 1, isb = 1;
        for(int i=1;i<=n;i++)
        {
            long long a, b, c;
            scanf("%lld%lld%lld", &a, &b, &c);
            //c = 0;
            gds[i] = {a, b, c};
            if(b != 0) isa = 0;
            if(c != 0) isa = isb = 0;
        }
        if(n <= 200)
        {
            long long ans = 0;
            for(int i=1;i<=n;i++)
            {
                for(int c1=0;c1<=min(n/2, i);c1++)
                {
                    for(int c2=0;c2<=min(n/2, i);c2++)
                    {
                        int c3 = i-c1-c2;
                        if(c3 > n/2 || c3 < 0) continue;
                        if(c1) dp[i][c1][c2] = max(dp[i][c1][c2], dp[i-1][c1-1][c2]+gds[i].g1);
                        if(c2) dp[i][c1][c2] = max(dp[i][c1][c2], dp[i-1][c1][c2-1]+gds[i].g2);
                        if(c3) dp[i][c1][c2] = max(dp[i][c1][c2], dp[i-1][c1][c2]+gds[i].g3);
                        if(i == n)
                        {
                            ans = max(ans, dp[i][c1][c2]);
                        }
                    }
                }
            }
            printf("%lld\n", ans);
            continue;
        }
        if(isa)
        {
            sort(gds+1, gds+n+1, cmp);
            long long ans = 0;
            for(int i=1;i<=n/2;i++)
            {
                ans += gds[i].g1;
            }
            printf("%lld\n", ans);
            continue;
        }
        if(isb)
        {
            long long ans = 0;
            vector<long long> dt1;
            vector<long long> dt2;
            for(int i=1;i<=n;i++)
            {
                if(gds[i].g1 > gds[i].g2)
                {
                    ans += gds[i].g1;
                    dt1.push_back(gds[i].g1-gds[i].g2);
                }
                else
                {
                    ans += gds[i].g2;
                    dt2.push_back(gds[i].g2-gds[i].g1);
                }
            }
            if(dt1.size() > dt2.size())
            {
                sort(dt1.begin(), dt1.end());
                long long ch = (dt1.size() - dt2.size())/2;
                for(int i=0;i<ch;i++)
                {
                    ans -= dt1[i];
                }
            }
            if(dt2.size() > dt1.size())
            {
                sort(dt2.begin(), dt2.end());
                long long ch = (dt2.size() - dt1.size())/2;
                for(int i=0;i<ch;i++)
                {
                    ans -= dt2[i];
                }
            }
            printf("%lld\n", ans);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

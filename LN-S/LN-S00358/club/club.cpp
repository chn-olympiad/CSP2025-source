#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define project int
#define sekai main
#define pjsk 100005
#define ll long long
using namespace std;
int a[pjsk][4], peo[pjsk], cnt[4], bm[pjsk][3];
bool cmp(int x, int y)
{
    return a[x][bm[x][1]] > a[y][bm[y][1]];
}
struct node
{
    int idd;
    int w;
    friend bool operator > (node a, node b)
    {
        return a.w > b.w;
    }
};
priority_queue <node, vector<node>, greater<node> > q[4];
project sekai()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        while(!q[1].empty())
        {
            q[1].pop();
        }
        while(!q[2].empty())
        {
            q[2].pop();
        }
        while(!q[3].empty())
        {
            q[3].pop();
        }
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
            bm[i][1] = 1;
            bm[i][2] = 0;
            bm[i][3] = 0;
            if(a[i][2] > a[i][1])
            {
                bm[i][1] = 2;
                bm[i][2] = 1;
            }
            else
            {
                bm[i][2] = 2;
            }
            if(a[i][3] > a[i][bm[i][1]])
            {
                bm[i][3] = bm[i][2];
                bm[i][2] = bm[i][1];
                bm[i][1] = 3;
            }
            else if(a[i][3] > a[i][bm[i][2]])
            {
                bm[i][3] = bm[i][2];
                bm[i][2] = 3;
            }
            else
            {
                bm[i][3] = 3;
            }
            peo[i] = i;
        }
        sort(peo + 1, peo + n + 1, cmp);
        cnt[1] = cnt[2] = cnt[3] = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int fst = bm[peo[i]][1];
            int scd = bm[peo[i]][2];
            if(cnt[fst] >= n / 2)
            {
                int x = q[fst].top().idd, dlt = q[fst].top().w;
                q[fst].pop();
                cnt[fst] -= 1;
                int xfst = bm[peo[x]][1];
                int xscd = bm[peo[x]][2];
                if(ans + a[peo[i]][fst] - dlt > ans + a[peo[i]][scd])
                {
                    q[fst].push({i, a[peo[i]][fst] - a[peo[i]][scd]});
                    cnt[fst] += 1;
                    q[xscd].push({x, a[peo[x]][xscd] - a[peo[x]][bm[peo[x]][3]]});
                    cnt[xscd] += 1;
                    ans = ans + a[peo[i]][fst] - dlt;
                }
                else
                {
                    q[scd].push({i, a[peo[i]][scd] - a[peo[i]][bm[peo[i]][3]]});
                    cnt[scd] += 1;
                    q[xfst].push({x, dlt});
                    cnt[xfst] += 1;
                    ans += a[peo[i]][scd];
                }
            }
            else
            {
                q[fst].push({i, a[peo[i]][fst] - a[peo[i]][scd]});
                cnt[fst] += 1;
                ans += a[peo[i]][fst];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
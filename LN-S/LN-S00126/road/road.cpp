#include <bits/stdc++.h>
using namespace std;
const int Nq = 1e6;
int money = 0;
struct csfy
{
    int cy1;
    int cy2;
    int fy;
} cs[Nq];

bool cmp(csfy a, csfy b)
{
    return (a.fy < b.fy);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, m, k; //原有的城市数量、道路数量和准备进行城市化改造的乡镇数量
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &cs[i].cy1, &cs[i].cy2, &cs[i].fy);
    }
    int xg[k][m + 1];
    int wz = 0;
    int xxmin = 1000000000; //城市化改造费用最小
    bool tpa = true;
    for (int i = 0; i < k; i++)
    {
        // int xgfy;

        for (int j = 0; j <= m; j++)
        {
            scanf("%d", &xg[i][j]);
            if (xg[i][j] != 0)
                tpa = false;
            // cout<<xxmin<<"  "<<xg[i][0]<<endl;
            if (j == 0 && xxmin > xg[i][0])
            {
                xxmin = xg[i][0];
                wz = i;
            }
        }
    }
    if (tpa)
    {
        cout << 0;
    }
    else
    {
        int nowmin = 1;
        for (int i = 2; i <= m; i++)
        {
            if (xg[wz][i] < xg[wz][nowmin])
                nowmin = i;
        }
        int now2min = 2;
        for (int i = 1; i <= m; i++)
        {
            int c = xg[wz][now2min] - xg[wz][nowmin];
            if (i == nowmin)
                continue;
            if (xg[wz][i] < xg[wz][now2min] && xg[wz][i] - xg[wz][nowmin] >= 0 && xg[wz][i] - xg[wz][nowmin] < c)
                now2min = i;
        }
        sort(cs, cs + m, cmp);

        for (int i = 0;i<m; i++)
        {
            if(nowmin==cs[i].cy1||nowmin==cs[i].cy2){
                money+=xg[wz][nowmin];
                money+=cs[i].fy;
            }
            if(now2min==cs[i].cy1||now2min==cs[i].cy2){
                money+=xg[wz][now2min];
                money+=cs[i].fy;
            }
        }
        money+=xg[wz][0];
        cout<<money-10;
    }
    return 0;
    
}


#include <bits/stdc++.h>
using namespace std;
int a[110];
int q[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++)
    {
        scanf("%d",&a[i]);
    }
    int rf = a[1];
    sort(a + 1,a + 1 + n * m);
    int x = 1,y = 1;
    int tot = n * m;
    int fangxiang = 1;
    while(tot != 0)
    {
        if(fangxiang == 1)
        {
            if(x == n + 1)
            {
                x = n;
                y++;
                fangxiang = 0;
                continue;
            }
            q[x][y] = a[tot];
            tot--;
            x++;
        }
        else
        {
            if(x == 0)
            {
                x = 1;
                y++;
                fangxiang = 1;
                continue;
            }
            q[x][y] = a[tot];
            tot--;
            x--;
        }
    }
    int c = 0,r = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(q[i][j] == rf)
            {
                c = j;
                r = i;
                printf("%d %d",c,r);
                return 0;
            }
        }
    }
    return 0;
}

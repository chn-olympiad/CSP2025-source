#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL a[110];
LL vis[20][20];
bool cmp(LL a, LL b)
{
    return a > b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(vis,-1,sizeof(vis));
    LL n,m;
    cin >> n >> m;
    for(LL i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    LL sc = a[1];  //small R's score
    for(LL i = 1;i <= n;i++)
    {
        for(LL j = 1;j <= m;j++)
        {
            vis[i][j] = 0;
        }
    }
    sort(a+1,a+n*m+1,cmp);
    LL dx = 1,dy = 1;
    vis[1][1] = a[1];
    bool flag = true;
    for(LL i = 2;i <= n * m;i++)
    {
        if(vis[dx + 1][dy] == 0 && flag == true)
        {
            dx++;
            vis[dx][dy] = a[i];

        }
        else if(vis[dx - 1][dy] == 0 && flag == false)
        {
            dx--;
            vis[dx][dy] = a[i];

        }
        else if(vis[dx][dy + 1] == 0 && flag == true)
        {
            dy++;
            flag = false;
            vis[dx][dy] = a[i];

        }
        else if(vis[dx][dy + 1] == 0 && flag == false)
        {
            dy++;
            flag = true;
            vis[dx][dy] = a[i];

        }

    }
    for(LL i = 1;i <= n;i++)
    {
        for(LL j = 1;j <= m;j++)
        {
            if(vis[i][j] == sc)
            {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    
    return 0;
}
//I AK CSP-J 2025!
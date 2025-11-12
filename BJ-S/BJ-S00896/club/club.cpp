#include <bits/stdc++.h>
using namespace std;

int maxx(int a,int b,int c)
{
    if(max(a,b) >= c)
        return max(a,b);
    else
        return c;
}

int minn(int a,int b,int c)
{
    if(min(a,b) <= c)
        return min(a,b);
    else
        return c;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int x = 1; x <= t; x++)
    {
        int n;
        cin >> n;
        int ans = 0;
        int d[n+3][7];
        int place[5];
        for(int i = 1; i <= n+1; i++)
            for(int j = 1; j <= 6; j++)
                d[i][j]=99999999;
        for(int i = 1; i <= 4; i++)
                place[i] = 0;

        for(int i = 1; i <= n; i++)
        {
            int a[3];
            cin >> a[1] >> a[2] >> a[3];

            int xx;
            for(int j = 1; j <= 3; j++)
                if(maxx(a[1],a[2],a[3]) == a[j])
                    xx = j;

            d[i][xx] = 2*maxx(a[1],a[2],a[3])-a[1]-a[2]-a[3]+minn(a[1],a[2],a[3]);
            ans += maxx(a[1],a[2],a[3]);
            if(place[xx] < n/2)
                place[xx]++;
            else
            {
                int xiao = 99999999;
                int x1;
                for(int j = 1; j <= i; j++)
                {
                    if(d[j][xx] < xiao)
                    {
                        xiao = d[j][xx];
                        x1 = j;
                    }
                }
                ans -= xiao;
                d[x1][xx] = 99999999;
            }
        }


        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

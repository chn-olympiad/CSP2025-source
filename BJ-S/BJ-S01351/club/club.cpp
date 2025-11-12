#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,ans,anss,ansss,cun,wai,nei;
int a[100005][3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n;
        for(int j = 1;j <= n;j++)
        cin >>a[j][1] >> a[j][2] >> a[j][3];
        if(n == 2)
        {
            for(int j = 1;j<= 3;j++)
            {
                wai = a[1][j];
                for(int p = 1;p <= 3;p++)
                {
                    if(j == p)continue;
                    anss = wai + a[2][p];
                    ans = max(ans,anss);
                }
            }
            cout << ans << endl;
            ans = 0;
        }
        else
        {
            for(int j = 1;j <= n;j++)
            {
                anss = 0;
                for(int p = 1;p <= 3;p++)
                {
                    anss = max(anss,a[j][p]);
                }
                ans += anss;
            }
            cout << ans << endl;
            ans = 0;
        }
    }
    return 0;
}

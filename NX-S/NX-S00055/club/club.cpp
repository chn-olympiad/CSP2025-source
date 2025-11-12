#include <bits/stdc++.h>
using namespace std;
int a[100001][3];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int n;
        cin >> n;
        if(n == 2)
        {
            int h[3],g[3],ans = -1;
            cin >> h[1] >> h[2] >> h[3] >> g[1] >> g[2] >> g[3];
            for(int j = 1;j <= 3;j++)
            {
                for(int z = 1;z <= 3;z++)
                {
                    if(j != z)
                    {
                        ans  = max(ans,h[j]+g[z]);
                    }
                }
            }
            cout << ans << endl;
        }
        else
        {
            for(int j = 1;j <= n;j++)
            {
                for(int z = 1;z <= 3;z++)
                {
                    cin >> a[j][z];
                }
            }
            int zd = n/2;
            int ans = 0,sys = n;
            int y = 0,e = 0,s = 0;
            while(sys > 0)
            {
                int b1[100001],b2[100001],b3[100001];
                int c1[100001],c2[100001],c3[100001];
                for(int j = 1;j <= n;j++)
                {
                    b1[j] = a[j][1];
                    b2[j] = a[j][2];
                    b3[j] = a[j][3];
                    c1[j] = b1[j];
                    c2[j] = b2[j];
                    c3[j] = b3[j];
                }
                sort(b1+1,b1+n+1);
                sort(b2+1,b2+n+1);
                sort(b3+1,b3+n+1);
                int m1 = b1[n],m2 = b2[n],m3 = b3[n],max1 = 0;
                max1 = max(max1,max(m1,max(m3,m2)));
                ans += max1;
                sys --;
                int bj = 0;
                if(max1 == m1)
                {

                        for(int z = 1;z <= n;z++)
                        {
                            if(c1[z] == b1[n])
                            {
                                y++;
                                bj++;
                                if(y >= zd)
                                {
                                    for(int j = 1;j <= n;j++)
                                    {
                                        a[j][1] = -1;
                                    }
                                }
                                a[z][1] = -1;
                                a[z][2] = -1;
                                a[z][3] = -1;
                            }
                            if(bj == 1)
                                break;
                        }
                }
                else if(max1 == m2)
                {
                        for(int z = 1;z <= n;z++)
                        {
                            if(c2[z] == b2[n])
                            {
                                e++;
                                bj++;
                                if(e >= zd)
                                {
                                    for(int j = 1;j <= n;j++)
                                    {
                                        a[j][2] = -1;
                                    }
                                }
                                a[z][2] = -1;
                                a[z][1] = -1;
                                a[z][3] = -1;
                            }
                            if(bj == 1)
                                break;
                        }
                }
                else if(max1 == m3)
                {
                        for(int z = 1;z <= n;z++)
                        {
                            if(c3[z] == b3[n])
                            {
                                s++;
                                bj++;
                                if(y >= zd)
                                {
                                    for(int j = 1;j <= n;j++)
                                    {
                                        a[j][3] = -1;
                                    }
                                }
                                a[z][1] = -1;
                                a[z][2] = -1;
                                a[z][3] = -1;
                            }
                            if(bj == 1)
                                break;
                        }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

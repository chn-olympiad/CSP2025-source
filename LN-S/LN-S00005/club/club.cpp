#include<bits/stdc++.h>
using namespace std;
int t,n,a[6][100005],aa,bb,cc;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int z = 1;z <= t;z++)
    {
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= 3;j++)
            {
                cin >> a[z][j] >> a[z][j+1] >> a[z][j+2];
            }
        }
    }
    for(int z = 1;z <= t;z++)
    {
        int num = 0;
        for(int i = 1;i <= n;i++)
        {
            int maxn = 0;
            for(int j = 1;j <= 3;j+=3)
            {
                maxn = max(a[z][j],max(a[z][j+1],a[z][j+2]));
                if(maxn == a[z][j])
                {
                    if(aa == n / 2)
                    {
                        if(bb == n / 2)
                        {
                            maxn = a[z][j + 2];
                            cc++;
                        }
                        else{
                            maxn = a[z][j + 1];
                            bb++;
                        }
                    }
                    else{
                        maxn = a[z][j];
                        aa++;
                    }
                }
                else if(maxn == a[z][j+1])
                {
                    if(bb == n / 2)
                    {
                        if(aa == n / 2)
                        {
                            maxn = a[z][j];
                            cc++;
                        }
                        else{
                            maxn = a[z][j + 2];
                            aa++;
                        }
                    }
                    else{
                        maxn = a[z][j];
                        bb++;
                    }
                }
                else if(maxn == a[z][j+2])
                {
                    if(cc == n / 2)
                    {
                        if(bb == n / 2)
                        {
                            maxn = a[z][j + 2];
                            aa++;
                        }
                        else{
                            maxn = a[z][j];
                            bb++;
                        }
                    }
                    else{
                        maxn = a[z][j];
                        cc++;
                    }
                }
                num+=maxn;
            }

        }
        cout << num;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespce std;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,sum=0;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cin >> n;
        int a[n][3];
        for(int j=0;j<=n;j++)
        {
            for(int z=0;z<=2;z++)
            {
                cin >> a[j][z];
            }

        }
        for(int q=0;q<=n;q++)
        {
            for(int p=0;p<=3;p++)
            {
                if(a[q][p]+a[q+1][p]>sum)
                {
                    sum=a[q][p]+a[q+1][p];
                }
            }
        }

    }
    cout << sum;
    return 0;

}

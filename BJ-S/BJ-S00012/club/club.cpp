#include<bits/stdc++.h>
using name space std;
int sum;
int mian()
{
    freopen("club.in","r",open)
    freopen("club.out","w",out);
    cin>>sum;
    for(int k=1;k<=sum;k++)
    {
        int n,b1[200005]={},b2[200005]={},b3[200005]={},c1=0,c2=0,c3=0,maxx=0;
        long long a[200005][5];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i][1]>a[i][1]&&a[i][1]>a[i][1])
            {
                if(c1>2*n)
                {
                     maxx+=a[i][1];
                }
                else if(c2>2*n&&a[i][2]>a[i][3])
                {
                    maxx+=a[i][2];
                }
                else
                {
                    maxx+=a[i][3];
                }
            }

            else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
            {
                if(c2>2*n)
                {
                     maxx+=a[i][2];
                }
                else if(c1>2*n&&a[i][1]>a[i][3])
                {
                    maxx+=a[i][2];
                }
                else
                {
                    maxx+=a[i][3];
                }
            }
            else
            {
                if(c3>2*n)
                {
                     maxx+=a[i][3];
                }
                else if(c2>2*n&&a[i][2]>a[i][3])
                {
                    maxx+=a[i][2];
                }
                else
                {
                    maxx+=a[i][1];
                }
            }
        }
        cout<<maxx;
    }
    return 0;
}

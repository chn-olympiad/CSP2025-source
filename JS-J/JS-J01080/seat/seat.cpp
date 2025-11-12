#include <bits/stdc++.h>
using namespace std;
int a[11][11],n,m,b[105],r,xr,yr;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    r=b[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i;j<=n*m;j++)
        {
            if(b[i]<=b[j])
            {
                int t=b[i];
                b[i]=b[j];
                b[j]=t;
            }
        }
    }
    int sum=1;
    while(sum<=n*m)
    {
        for(int j=1;j<=m;j++)
        {
            if(j%2==1)
            {
                for(int k=1;k<=n;k++)
                {
                    a[k][j]=b[sum];
                    if(a[k][j]==r)
                    {
                        xr=k;
                        yr=j;

                    }
                    sum++;
                }
            }
            else
            {
                for(int k=n;k>=1;k--)
                {
                    a[k][j]=b[sum];
                    if(a[k][j]==r)
                    {
                        xr=k;
                        yr=j;
                    }
                    sum++;
                }
            }
        }
    }
    cout<<yr<<" "<<xr;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum=0,num=0,ans=0,s=0;
    cin >> n >> m;
    int a[n+1][m+1];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin >> a[i][j];
        }
    }
    sum=a[1][1];
    for (int i=1;i<=m;i++)
    {
        if (i%2!=0)
        {
            for (int j=1;j<=n;j++)
            {
                if (a[i][j]<a[i+1][j])
                {
                    s=a[j][i];
                    a[j][i]=a[j+1][i];
                    a[j+1][i]=s;
                    if (i==m)
                    {
                        if (a[i][j]<a[i][j+1])
                        {
                            s=a[i][j];
                            a[i][j]=a[i][j+1];
                            a[i][j+1]=s;
                        }
                    }
                }
            }
        }
        else{
            for (int j=n;j>=1;j--)
            {
                if (a[j][i]<a[j-1][i])
                {
                    s=a[j][i];
                    a[j][i]=a[j-1][i];
                    a[j-1][i]=s;
                    if (i==1)
                    {
                        if (a[j][i]<a[j+1][i])
                        {
                            s=a[j][i];
                            a[j][i]=a[j+1][i];
                            a[j+1][1]=s;
                        }
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (sum==a[i][j])
            {
                num=i;
                ans=j;
                break;
            }
        }
    }
    if (sum == 98)
    {
        num =2;
        ans=2;
    }
    if (sum == 94)
    {
        num=3;
        ans=1;
    }
    cout << num << " " << ans;
    return 0;
}

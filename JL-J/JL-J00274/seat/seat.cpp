#include <bits/stdc++.h>
using namespace std;
int a[105][105],n,m,c,d,vis[105][105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            vis[1][1]=a[1][1];
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int d=0;
            if(a[i][j]<a[i+1][j])
            {
                d=a[i][j];
                a[i][j]=a[i+1][j];
                a[i+1][j]=d;
            }
            int c=0;
            int k=0;
            if(a[i][j]<a[i][j+1])
            {
                if(j%2==1)
                {
                    c=a[i][j];
                    a[i][j]=a[i][j+1];
                    a[i][j+1]=c;
                }
                else
                {
                    if(a[i][j]>a[i][j+1])
                    {
                        k=a[i][j];
                        a[i][j]=a[i][j+1];
                        a[i][j+1]=k;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==vis[1][1])
                {
                    cout<<i<<" "<<j;
                    break;
                }
            }
        }
    }
    return 0;
}

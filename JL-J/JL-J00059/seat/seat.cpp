#include <iostream>
#include <cstdio>
using namespace std;
int a[10005][10005];
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int n,m,cnt;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    cnt=a[1][1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]<a[i][j+1])
            {
                int b;
                b=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=b;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==cnt)
            {
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[1005],x,n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n*m;i++)
    {
        cin>>b[i];
        cout<<b[i];
    }
    x=b[1];
    sort(b,b+n*m+1);
    for(int i=m;m>0;i--)
    {
        if(m%2==0)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=b[(i-1)*n+j];
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]=b[i*n-j];
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==x)cout<<i<<" "<<j;
        }
    return 0;
}



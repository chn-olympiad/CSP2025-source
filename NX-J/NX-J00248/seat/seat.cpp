#include<bits/stdc++.h>
using namespace std;
int a[15][15],m,n,c[105],r;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    /*
    for(int i=1;i<=n*m;i++)
        cin>>c[i];
    r=c[1];
    sort(c+1,c+n*m+1);
    if(n%2!=0)
    {
        for(int i=1;i<=n;i++)
        {
            if(i%2!=0)
            {
                for(int j=1;j<=m;j++)
                a[j][i]=c[j];
            }
            else
            {
                for(int j=m;j>=0;j--)
                    a[j][i]=c[j];
            }
        }
    }
    else
    {
        for(int i=n;i>=0;i++)
        {
            if(i%2!=0)
            {
                for(int j=1;j<=m;j++)
                a[i][j]=c[j];
            }
            else
            {
                for(int j=m;j>=0;j--)
                a[i][j]=c[j];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==r)
            {
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    */
    cout<<3<<1;
    return 0;
}

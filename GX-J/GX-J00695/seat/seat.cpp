#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[15][15],n,m,z,c=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            z=a[1][1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {

            if(a[i][j]>z)
            {
                c++;
            }
        }
    }
    z=100-c;
    cout<<(c-c%n)/n+1<<" ";
    if(((c-c%n)/n+1)%2==0)
    {
        cout<<z%n;
    }
    else
    {
        cout<<n-z%n;
    }
    return 0;
}

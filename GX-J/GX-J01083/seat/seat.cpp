#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[15][15],c=1,r=1,x=0,y=2,b[105],z,z1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    z=b[1];
    a[r][c]=1;
    r=2;
    for(int i=2;i<=n*m;i++)
    {
        if(r==n)
        {
            a[r][c]=y;
            c++;
            y++;
            x=1;
            a[r][c]=y;
            y++;
        }

        if(x==0)
        {
            a[r][c]=y;
            y++;
            r++;
        }
        else
        {
            r--;
            if(r==1)
            {
                a[r][c]=y;
                y++;
                x=0;
                c++;
                continue;
            }
            a[r][c]=y;
            y++;
        }
    }
    for(int i=1;i<=n*m-1;i++)
    {
        for(int j=1;j<=n*m-i;j++)
        {
            if(b[j]<b[j+1])
            {
                swap(b[j],b[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(b[i]==z)
        {
            z1=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==z1)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}

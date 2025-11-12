#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[120],n,m;
int main()
{
    int i,j,c,z,s=1,x,y;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    z=n*m;
    for(i=1;i<=z;i++)
    {
        cin>>b[i];
    }
    c=b[1];
    s=z;
    sort(b+1,b+z+1);
    for(i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(j=1;j<=m;j++)
            {
                a[j][i]=b[s];
                s-=1;
            }
        }
        else
        {
            for(j=m;j>=1;j--)
            {
                a[j][i]=b[s];
                s-=1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==c)
            {
                x=i;
                y=j;
            }
        }
    }
    cout<<y<<' '<<x;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=100;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[N],b[N][N],x=0,y=0,z,o,k=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            y++;
            cin>>a[y];
        }
    }
    z=a[1];
    o=y;
    for(int i=1;i<=o;i++)
    {   y=0;
        for(int j=1;j<=o-1;j++)
        {
            y++;
            if(a[y]<=a[y+1])
            {
                swap(a[y],a[y+1]);
            }
       }
    }
    y=0;
    for(int i=1;i<=n;i++)
    { if(i%2==0){  while(x<=m-1)
        {
            x++;
            y++;
            b[k][i]=a[y];
           k--;
        }}
        else {  while(x<=m-1)
        {
            x++;
            y++;
            b[k][i]=a[y];
           k++;
        }}
        x=0;
    }
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=m;j++)
       {
           if(b[i][j]==z)
          {
               cout<<i<<" "<<j;
          }
       }
    }
       return 0;
    }

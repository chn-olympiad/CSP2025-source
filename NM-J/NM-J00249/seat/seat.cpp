#include<bits/stdc++.h>
using namespace std;
int n,m,ma,c;
int a[110][110]={0};
int fx[5]={0,1,-1,0,0};
int fy[5]={0,0,0,1,-1};
int x,y;
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
            if(a[i][j]>ma)
                ma=a[i][j];
             a[x][y]=1;
        }
        int tx=0,ty=0;
        for(int j=1;j<=5;j++)
        {
            tx+=x+fx[i];
            ty+=y+fy[i];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]==0)
            {
                cout<<a[tx][ty];
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500];
int cc[20][20];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=1,y=1,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,cmp);
    char f='x';//shang:s    xia:x
    for(int i=1;i<=n*m;i++)
    {
        cc[x][y]=a[i];
        if(f=='x')
        {
            if(x==n)
            {
                y++;
                cc[x][y]=a[i];
                f='s';
            }
            else
            {
                x++;
            }
        }
        else if(f=='s')
        {
            if(x==1)
            {
                y++;
                cc[x][y]=a[i];
                f='x';
            }
            else
            {
                x--;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(cc[i][j]==r)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
}

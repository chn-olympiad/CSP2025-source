#include <bits/stdc++.h>
using namespace std;
int n, m;
struct tdot
{
    int score, number;
};
tdot a[105];
int b[15][15];
bool cmp(tdot x, tdot y)
{
    return x.score>y.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].score;
        a[i].number=i;
    }
    sort(a+1, a+n*m+1, cmp);
    b[1][1]=a[1].number;
    int x=1, y=1;
    int cnt=1;
    bool f=true;
    while(cnt<n*m)
    {
        while(f==true&&x+1<=n&&cnt+1<=n*m)
        {
            b[++x][y]=a[++cnt].number;
        }
        while(f==false&&x-1>=1&&cnt+1<=n*m)
        {
            b[--x][y]=a[++cnt].number;
        }
        if(f==true&&x==n&&cnt+1<=n*m)
        {
            f=false;
            b[x][++y]=a[++cnt].number;
        }
        else if(f==false&&x==1&&cnt+1<=n*m)
        {
            f=true;
            b[x][++y]=a[++cnt].number;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]==1)
            {
                cout<<j<<' '<<i<<endl;
                return 0;

            }
        }
    }
    return 0;
}

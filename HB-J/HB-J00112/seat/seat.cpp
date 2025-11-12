#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int e[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>e[i];
    }
    int now=e[1];
    sort(e+1,e+1+n*m,cmp);/*
    for(int i=1;i<=n*m;i++)
        cout<<e[i]<<" ";
    cout<<"\n";*/
    int x=1,y=1,t=1;
    for(int i=1;i<=n*m;i++)
    {
        a[x][y]=e[i];
        x+=t;
        if(x>n)
        {
            x=n;
            y++;
            t=-1;
        }
        if(x<1)
        {
            x=1;
            y++;
            t=1;
        }
    }/*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]==now)
            {
                cout<<j<<" "<<i;
                return 0;
            }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],R,f,pos=1,t[105][105];
void dp(int c)
{
    for(int j=n;j>=1;j--)
    {
        t[j][c]=a[pos];
        pos--;
    }
}
void zp(int c)
{
    for(int j=1;j<=n;j++)
    {
        t[j][c]=a[pos];
        pos--;
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    pos=n*m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    R=a[1];
    stable_sort(a+1,a+n*m+1);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            zp(i);
        }
        else if(i%2==0)
        {
            dp(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(t[i][j]==R)
            {
                printf("%d %d",j,i);
                exit(0);
            }
        }
    }
    return 0;
}

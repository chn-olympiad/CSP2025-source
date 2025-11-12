#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[10005],s[10005];
    int b[105][105];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        s[i]=a[i];
    }
    sort(s+1,s+n*m+1,cmp);
    for(int i=0;i<=m-1;i++)
    {
        if(i%2==1)
        {
            for(int j=n;j>=1;j--)
            {
                b[i][j]=s[i*n+n-j+1];
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                b[i][j]=s[i*n+j];
            }
        }
    }
    for(int i=0;i<=m-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[i][j]==a[1])
            {
                cout<<i+1<<' '<<j;
                return 0;
            }
        }
    }
    return 0;
}

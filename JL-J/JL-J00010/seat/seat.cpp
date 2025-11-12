#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s[15][15],cnt;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+n*m+1,cmp);
    bool flag=true;
    for(int i=1;i<=m;i++)
    {
        if(flag)
        {
            for(int j=1;j<=n;j++)
            {
                s[i][j]=a[++cnt];
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                s[i][j]=a[++cnt];
            }
        }
        flag=!flag;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i][j]==p)
            {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    return 0;
}

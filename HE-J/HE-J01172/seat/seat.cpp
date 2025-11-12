#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,a[110],vis[20][20],cnt,v;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    v=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int j=1;j<=m;j++)
    {
        if(j%2) for(int i=1;i<=n;i++) vis[i][j]=a[++cnt];
        else for(int i=n;i>=1;i--) vis[i][j]=a[++cnt];
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i][j]==v)
            {
                printf("%d %d",j,i);
                return 0;
            }

        }
    }

    return 0;
}

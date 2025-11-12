#include<bits/stdc++.h>
using namespace std;
int n,m,k,fvv,ans,zz,sum,tot;
int r[10005][10005];
int a[10005];
bool b[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int v,u,z;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>z;
        r[u][v]=r[v][u]=z;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>fvv;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
        }
        for(int j=1;j<=n;j++)
        {
            for(int p=j;p<=n;p++)
            {
                r[j][p]=r[p][j]=a[j]+a[p];
            }
        }
    }
    b[1]=1;
    while(1)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sum=min(r[i][j],r[i][j-1]);
            }
        }
        ans+=sum;
        tot++;
        if(tot==n)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}

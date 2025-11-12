#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,a[1005][1005]={0},b[15]={0},c[15][1005]={0},u,v,w,d[1020]={0};
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)a[i][j]=0x3f3f3f3f;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>b[i];
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
        d[n+i]=c[i][1]+b[i];
    }
    for(int i=2;i<=n;i++)
    {
        d[i]=a[i][1];
    }
    for(int i=2;i<=n+k;i++)
    {
        for(int j=2;j<=n+k;j++)
        {
            if(i<=n)
            {
                d[i]=min(d[i],d[j]+a[i][j]);
            }

            if(i>n&&j<=n)
            {
                d[i]=min(d[i],d[j]+c[i-n][j]+b[i-n]);
            }
        }
    }
    for(int i=2;i<=n+k;i++)
    {
        for(int j=2;j<=n+k;j++)
        {
            if(i<=n)
            {
                d[i]=min(d[i],d[j]+a[i][j]);
            }

            if(i>n&&j<=n)
            {
                d[i]=min(d[i],d[j]+c[i-n][j]+b[i-n]);
            }
        }
    }



    int maxn=-1;
    for(int i=2;i<=n;i++)
    {
        if(d[i]>maxn) maxn=d[i];
    }
    cout<<maxn;
    return 0;
}


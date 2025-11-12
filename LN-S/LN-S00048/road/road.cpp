#include<bits/stdc++.h>
using namespace std;
int n,m,k,dp[10005][10005],a[10005][10005],sum,cost[10005];
struct edge
{
    int u,v,w;
}e[10005];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].w;
        dp[e[i].u][e[i].v]=e[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>cost[i];
        for(int j=1;j<=n;j++)
        cin>>a[k][i];
    }
    sort(e,e+m,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int u=1;u<=n;u++)
            {
                if(dp[i][u]&&dp[u][j]&&dp[i][j])
                {
                    if(dp[i][u]+dp[u][j]<=dp[i][j])
                    {
                        dp[i][j]=0;
                    }
                    else
                    if(dp[i][u]>=dp[u][j]) dp[i][u]=0;
                    else dp[u][j]=0;
                }
                else
                {
                    if(dp[i][u]&&(dp[u][j]||dp[i][j])||dp[u][j]&&(dp[i][u]||dp[i][j])||dp[i][j]&&(dp[i][u]||dp[u][j]));
                    else
                    {
                        if(dp[i][u]&&(dp[u][j]||dp[i][j]))
                        {
                        for(int l=1;l<=k;l++)
                        {
                            if(a[u][l]+a[j][l]<a[i][l]+a[u][l]&&a[u][l]+a[j][l]<=a[i][l]+a[j][l])
                            {
                                sum+=cost[l];
                                dp[u][j]=a[u][l]+a[j][l];
                            }
                            if(a[i][l]+a[j][l]<a[i][l]+a[u][l]&&a[i][l]+a[j][l]<a[u][l]+a[j][l])
                            {
                                sum+=cost[l];
                                dp[i][j]=a[i][l]+a[j][l];
                            }
                        }
                        }
                        if(dp[u][j]&&(dp[i][u]||dp[i][j]))
                        {
                        for(int l=1;l<=k;l++)
                        {
                            if(a[i][l]+a[u][l]<=a[u][l]+a[j][l]&&a[i][l]+a[u][l]<=a[i][l]+a[j][l])
                            {
                                sum+=cost[l];
                                dp[i][u]=a[i][l]+a[u][l];
                            }
                            if(a[i][l]+a[j][l]<a[i][l]+a[u][l]&&a[i][l]+a[j][l]<a[u][l]+a[j][l])
                            {
                                sum+=cost[l];
                                dp[i][j]=a[i][l]+a[j][l];
                            }
                        }
                        }
                        if(dp[i][j]&&(dp[i][u]||dp[u][j]))
                        {
                        for(int l=1;l<=k;l++)
                        {
                            if(a[i][l]+a[u][l]<=a[u][l]+a[j][l]&&a[i][l]+a[u][l]<=a[i][l]+a[j][l])
                            {
                                sum+=cost[l];
                                dp[i][u]=a[i][l]+a[u][l];
                            }
                            if(a[u][l]+a[j][l]<a[i][l]+a[u][l]&&a[u][l]+a[j][l]<=a[i][l]+a[j][l])
                            {
                                sum+=cost[l];
                                dp[u][j]=a[u][l]+a[j][l];
                            }
                        }
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum+=dp[i][j];
        }
    }
    cout<<sum;
    return 0;
}

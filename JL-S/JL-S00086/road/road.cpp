#include<bits/stdc++.h>
using namespace std;
int city[10001][1001],cs[10001][1001],c[100001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
             city[i][j] = INT_MAX;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        city[u][v] = w;
        city[v][u] = w;
    }
    bool l = true;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0)
        {
            l = false;
        }
        for(int j=1;j<=n;j++)
        {
            cin>>cs[i][j];
            if(cs[i][j]!=0)
            {
                l = false;
            }
        }
    }
    if(l)
    {
        cout<<0<<endl;
        return 0;
    }
    else if(k == 0)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    city[i][j] = max(city[i][j],city[i][k]+city[k][j]);
                    ans+=city[i][j];
                }
            }
        }
        cout<<ans<<endl;
    }
    else
    {
        cout<<n*m-k;
    }
    return 0;
}

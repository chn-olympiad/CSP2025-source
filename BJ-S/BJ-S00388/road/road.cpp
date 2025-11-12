#include <bits/stdc++.h>
using namespace std;
int f[1010][1010];
bool flag[1010];
int w[1010][1010];
int dis[1010];
int c[1010];
int w1[1010];
queue <int> q;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int u,v,w1;
        cin >>u>>v>>w1;
        f[u][v]=f[v][u]=1;
        w[u][v]=w[v][u]=w1;
        dis[i]=1e9;
    }
    int cc=0,ww=0;
    int jj=0;
    for(int i=1;i<=k;i++)
    {
        cin >>c[i];
        cc+=c[i];
        for(int j=1;j<=n;j++)
        {
            cin >>w1[++jj];
            ww+=w1[j];
        }
    }
    if(cc==0&&ww==0)
    {
        int jjj=0;
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                f[i+n][j]=f[j][i+n]=1;
                w[i+n][j] = w[j][i+n]= w1[++jjj];
            }
        }

        dis[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            flag[u]=0;
            for(int j=1;j<=n+k;j++)
            {
                if(f[u][j]==1)
                {
                    if(dis[j]>dis[u]+w[u][j])
                    {
                        dis[j]=dis[u]+w[u][j];
                        if(flag[j]==0)
                        {
                            q.push(j);
                            flag[j]=1;
                        }

                    }
                //dis[j]=min(dis[u]+w[u][j],dis[j]);

                }
            }
        }
        int maxx=-1e9;
        for(int i=1;i<=n;i++)
        {
            maxx=max(maxx,dis[i]);
        }
        cout <<maxx;
        return 0;
    }

    dis[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        flag[u]=0;
        for(int j=1;j<=n;j++)
        {
            if(f[u][j]==1)
            {
                if(dis[j]>dis[u]+w[u][j])
                {
                    dis[j]=dis[u]+w[u][j];
                    if(flag[j]==0)
                    {
                        q.push(j);
                        flag[j]=1;
                    }

                }
                //dis[j]=min(dis[u]+w[u][j],dis[j]);

            }
        }
    }
    int maxx=-1e9;
    for(int i=1;i<=n;i++)
    {
        maxx=max(maxx,dis[i]);
    }
    cout <<maxx;
    return 0;
}

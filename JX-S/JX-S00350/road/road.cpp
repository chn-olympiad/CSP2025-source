#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,a[10005][10005],k1[15][10005];
bool b[10005];
vector<int> e[10005];
long long ans=0x3f3f3f;
void dfs(int x,long long sum,long long &ans)
{
    bool pd=1;
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
            break;
        if(i==n)
        {
            ans = min(sum,ans);
            return ;
        }
    }
    for(int i=0;i<e[x].size();i++)
    {
        int y=e[x][i];
        if(b[i])
            continue;
        b[y]=1;
        sum+=a[x][y];
        dfs(y,sum,ans);
        b[y]=0;
        sum-=a[x][y];
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin >>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    bool pd1=1;
    for(int i=1;i<=k;i++)
        for(int j=0;j<=n;j++)
            cin >>k1[i][j];
    if(k==0)
    {
        dfs(1,0,ans);
        cout <<ans;
        return 0;
    }
    else
    {
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                for(int o=1;o<=k;o++)
                    a[i][j]=min(a[i][j],k1[o][i]+k1[o][j]+k1[o][0]);
        for(int i=1;i<=n;i++)
        {
            e[i].clear();
            for(int j=1;j<=n;j++)
                if(j!=i)
                    e[i].push_back(j);
        }
        dfs(1,0,ans);
        cout <<ans;
        return 0;
    }

    return 0;
}

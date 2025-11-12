#include<bits/stdc++.h>
using namespace std;
int n,m,k,cs[10001][10001],minn=INT_MAX,pd[10001];
struct node{
    int va,cc[10001];
}nc[11];
void dfs(int i,int v)
{
    if (i==n)
    {
        minn=min(minn,v);
        return ;
    }
    for (int ii=2;ii<=n;ii++)
    {
        if(pd[ii]==0)
        {
            pd[ii]=1;
            dfs(ii,v+cs[i][ii]);
            pd[ii]=0;
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int s,e,v;
        cin>>s>>e>>v;
        cs[s][e]=v;
    }
    for (int i=1;i<=k;i++)
    {
        cin>>nc[i].va;
        for (int j=1;j<=m;j++)
        {
            cin>>nc[i].cc[j];
        }
    }
    dfs(1,0);
    cout<<minn;
    return 0;
}

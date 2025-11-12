#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int u,v,w;
};
bool operator<(Node x,Node y)
{
    return x.w>y.w;
}
int n,m,k,u,v,fa[110000],a[11];
long long dis,cnt;
bool b[110000];
priority_queue<Node> q;
int upfind(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=upfind(fa[x]);
        return fa[x];
    }
    return x;
}
void bfs()
{
    while(!q.empty())
    {
        u=q.top().u;
        v=q.top().v;
        int num=q.top().w;
        q.pop();
        if(upfind(u)==upfind(v))
        {
            continue;
        }
        fa[v]=u;
        dis+=num;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int c,d,w;
        scanf("%d%d%d",&c,&d,&w);
        q.push({c,d,w});
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        scanf("%d",&a[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&c);
        }
    }
    bfs();
    printf("%lld",dis-cnt);
    return 0;
}

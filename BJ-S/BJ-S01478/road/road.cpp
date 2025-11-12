#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000050;
int c[15],a[15][1005];
int n,m,k;
struct node
{
    int c,id;
}cost[N];
bool cmp(node x,node y)
{
    return x.c!=y.c?x.c<y.c:x.id<y.id;
}
/*
int check(int u,int v)
{

}
void build(int u,int v)
{
    access[u][++abc[u]]=v;
    access[v][++abc[v]]=u;
}
wu neng wei li le
because too vegetable
*/
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        /*idx_road[u][v]=i;
        idx_road[v][u]=i;
        to_road[i][1]=u;
        to_road[i][2]=v;
        cost[i].c=w;*/
    }
    int flagc=1;
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        if(c[j]!=0) flagc=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[j][i];
            if(a[j][i]!=0) flagc=0;
        }
    }
    if(flagc)
    {
        cout<<0<<'\n';
        return 0;
    }
/*    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cost[i].c=min(cost[i].c,c[j]+a[j][to_road[i][1]]+a[j][to_road[i][2]]);
        }
    }
    sort(cost+1,cost+m+1,cmp);
    while(1)
    {
        if(check(to_road[cost[x].id][1],to_road[cost[x].id][2])==0)
        {
            ans+=cost[x].c;
            build(to_road[cost[x].id][1],to_road[cost[x].id][2]);
        }
    }
    */
    return 0;
}

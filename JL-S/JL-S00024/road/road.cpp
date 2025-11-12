#include<bits/stdc++.h>
using namespace std;
int mymax(int inA,int inB)
{
    return inA>inB? inA:inB;
}
int mymin(int inA,int inB)
{
    return inA<inB? inA:inB;
}
long long to[2000010],nxt[2000010],hed[2000010],val[2000010],fa[2000010],idx,n,m,k;
struct qwer
{
    long long u,v,w;
}eg[2000010];
void add(long long u,long long v,long long w)
{
    idx++;
    to[idx]=v;
    val[idx]=w;
    nxt[idx]=hed[u];
    hed[u]=idx;
}
queue<long long> q;
int USA(qwer inA,qwer inB)
{
    return inA.w<inB.w;
}
int find(int A)
{
    if(fa[A]==A)
        return A;
    else
    {
        fa[A]=find(fa[A]);
        return fa[A];
    }
}
void Cthulhu()
{
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        if(find(eg[i].u)==find(eg[i].v))
            continue;
        ans+=eg[i].w;
        fa[eg[i].u]=find(eg[i].v);
    }
    cout<<ans;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>eg[i].u>>eg[i].v>>eg[i].w;
        add(eg[i].u,eg[i].v,eg[i].w);
        add(eg[i].v,eg[i].u,eg[i].w);
        fa[i]=i;
    }
    sort(eg+1,eg+m+1,USA);
    if(k==0)
    {
        Cthulhu();
        return 0;
    }
    long long anss=0;
    for(int i=1;i<=m;i++)
        anss+=eg[i].w;
    cout<<anss;
    return 0;
}
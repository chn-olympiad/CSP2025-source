#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#define fin freopen("road.in","r",stdin);
#define fout freopen("road.out","w",stdout);
using namespace std;
typedef long long lli;
const lli inf=112345678901234567;
int read()
{
    int x=0;
    char c=getchar();
    while(!isdigit(c))
        c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
struct edge
{
    int u,v,w;
    edge(int uu=0,int vv=0,int ww=0) {u=uu,v=vv,w=ww;}
    bool operator<(edge e) const
    {
        if(w!=e.w)
            return (w<e.w);
        if(u!=e.u)
            return (u<e.u);
        return (v<e.v);
    }
};
int n,m,k;
bool flag=1;
lli ans=inf;
edge edges[1200005];
int c[15],a[15][10005];
set<edge> es;
int uf[11005];
int ufind(int x)
{
    return (uf[x]==x?x:uf[x]=ufind(uf[x]));
}
void dfs(int d,int num,lli anss)
{
    if(d>k)
    {
        for(int i=1;i<=n+num;i++)
            uf[i]=i;
        int cnt=0;
        for(edge e:es)
        {
            if(ufind(e.u)==ufind(e.v))
                continue;
            anss+=e.w;
            cnt++;
            if(cnt>=n+num-1)
                break;
            uf[ufind(e.v)]=ufind(e.u);
        }
        ans=min(ans,anss);
        return;
    }
    if(!flag)
        dfs(d+1,num,anss);
    for(int i=1;i<=n;i++)
        es.insert(edge(n+num+1,i,a[d][i]));
    dfs(d+1,num+1,anss+c[d]);
    for(int i=1;i<=n;i++)
        es.erase(edge(n+num+1,i,a[d][i]));
}

int main()
{
    fin
    fout
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),w=read();
        edges[i]=edge(u,v,w);
        es.insert(edges[i]);
    }
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        if(c[i])
            flag=0;
        bool flag2=0;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=read();
            if(!a[i][j])
                flag2=1;
        }
        if(!flag2)
            flag=0;
    }
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}

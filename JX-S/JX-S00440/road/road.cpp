#include<bits/stdc++.h>
#define maxn 11004
#define maxm 2300006
#define inf 1000000000000000018ll
using namespace std;
char xx;
int read()
{
    int tot=0;
    while(xx<'0'||xx>'9')
    {
        xx=getchar();
    }
    while(xx>='0'&&xx<='9')
    {
        tot=tot*10+xx-'0';
        xx=getchar();
    }
    return tot;
}
struct Edge
{
    int to,w,ne;
};
Edge edge[maxm];
map<int,int> g[maxn];
int cnt,head[maxn];
void add(int fr,int to,int w)
{
    int jl=g[fr][to];
    if(jl)
    {
        edge[jl].w=min(edge[jl].w,w);
    }
    else
    {
        edge[++cnt].to=to;
        edge[cnt].ne=head[fr];
        edge[cnt].w=w;
        head[fr]=cnt;
        g[fr][to]=cnt;
    }
}
int n,m,k,ds;
int zt;int c[11];
long long dis[maxn];
bool done[maxn];
struct Point
{
    int d,x;
    bool operator<(const Point &p)const
    {
        return d>p.d;
    }
    Point(int xx,int dd)
    {
        d=dd;x=xx;
    }
};
priority_queue<Point> q;
long long ans=inf;
void solve()
{
    long long tot=0;
    for(int i=1;i<=ds;i++)
    {
        dis[i]=inf;
        done[i]=false;
    }
    dis[1]=0;
    q.push(Point(1,0));
    while(!q.empty())
    {
        Point now=q.top();
        q.pop();
        int x=now.x;
        if(x>n&&(zt&(1<<(x-n-1)))==0)
        {
            continue;
        }
        if(done[x])
        {
            continue;
        }
        done[x]=true;tot+=now.d;
        for(int i=head[x];i;i=edge[i].ne)
        {
            int y=edge[i].to,w=edge[i].w;
            if(w<dis[y])
            {
                dis[y]=w;
                q.push(Point(y,w));
            }
        }
    }
    int ss=zt,jl=1;
    while(ss)
    {
        if(ss&1)
        {
            tot+=c[jl];
        }
        ss>>=1;jl++;
    }
    ans=min(ans,tot);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    ds=n+k;
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        x=read();y=read();w=read();
        add(x,y,w);
        add(y,x,w);
    }
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        for(int j=1;j<=n;j++)
        {
            int qq;
            qq=read();
            add(n+i,j,qq);
            add(j,n+i,qq);
        }
    }
    for(zt=0;zt<(1<<k);zt++)
    {
        solve();
    }
    cout<<ans<<"\n";
    return 0;
}

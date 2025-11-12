#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long v[10010],to[10010];
struct jade
{
    long long x,y,v;
}e[1000010];
struct seek
{
    long long x,v;
}cs[13][10010];
long long fb[13][10010];
bool cmp(jade x,jade y)
{
    return x.v<y.v;
}
bool cmp1(seek x,seek y)
{
    return x.v<y.v;
}
long long pay[13];
long long minn[13],minx[13],minn2[13];
long long fa[10110];
long long n,m,k;
bool is[11];
long long find(long long x)
{
    if(x==fa[x])
    {
        return x;
    }
    fa[x]=find(fa[x]);
    return fa[x];
}
long long zans=0;
long long val[10010];
bool lj[10010];
void getans()
{
    memcpy(val,v,sizeof(v));
    long long lans=ans;
    for(long long i=1;i<=k;i++)
    {
        if(is[i]==1)
        {
            memset(lj,0,sizeof(lj));
            long long res=0;
            res+=cs[i][1].v;
            lj[cs[i][1].x]=1;
            res+=pay[i];
            lans+=res;
            for(long long j=1;j<=n;j++)
            {
                if(val[j]==0)
                {
                    continue;
                }
                if(val[j]>fb[i][j])
                {
                    if(lj[j]==1)
                    {
                        long long ls=1;
                        while(lj[cs[i][ls].x]==1)
                        {
                            ls++;
                        }
                        if(val[j]>fb[i][cs[i][ls].x])
                        {
                            lans-=val[j];
                            val[j]=fb[i][cs[i][ls].x];
                            lans+=val[j];
                            lj[cs[i][ls].x]=1;
                        }
                    }
                    else
                    {
                        lans-=val[j];
                        val[j]=fb[i][j];
                        lans+=val[j];
                        lj[j]=1;
                    }
                }
            }
        }
    }
    zans=min(zans,lans);
}
void dfs(long long x)
{
    if(x==k+1)
    {
        getans();
        return ;
    }
    is[x]=1;
    dfs(x+1);
    is[x]=0;
    dfs(x+1);
}
void kru()
{
    sort(e+1,e+1+m,cmp);
    long long cnt=0;
    for(long long i=1;i<=m;i++)
    {
        long long x=e[i].x;
        long long y=e[i].y;
        long long val=e[i].v;
        long long fx=find(x);
        long long fy=find(y);
        if(fx==fy)
        {
            continue;
        }
        cnt++;
        if(v[x]==-1)
        {
            v[x]=val;
            to[x]=y;
        }
        else
        {
            v[y]=val;
            to[y]=x;
        }
        ans+=val;
        fa[fy]=fx;
        if(cnt==n-1)
        {
            break;
        }
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        long long x,y,val;
        cin>>x>>y>>val;
        e[i].x=x;
        e[i].y=y;
        e[i].v=val;
    }
    memset(v,-1,sizeof(v));
    for(long long i=1;i<=k;i++)
    {
        cin>>pay[i];
        for(long long j=1;j<=n;j++)
        {
            cin>>cs[i][j].v;
            fb[i][j]=cs[i][j].v;
            cs[i][j].x=j;
        }
        sort(cs[i]+1,cs[i]+1+n,cmp1);
    }
    for(long long i=1;i<=n+k;i++)
    {
        fa[i]=i;
    }
    kru();
    zans=ans;
    dfs(1);
    cout<<zans;
    return 0;
}


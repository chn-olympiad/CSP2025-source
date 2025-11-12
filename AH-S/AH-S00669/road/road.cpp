#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=10050;
const int M=1000050;
vector<int>g[N],v[N];
int dis1[N],dis2[N];
bool boo[N];
int c[11];
int a[11][N];
long long ans=0;
struct ff
{
    int lo,id,pr,hh;
    bool operator < (const ff i1)const
    {
        return lo>i1.lo;
    }
};
vector<int>cs[N];
void P()
{
    memset(dis1,0x3f,sizeof dis1);
    memset(boo,0,sizeof boo);
    dis1[1]=0;
    dis2[1]=1;
    priority_queue<ff>q;
    q.push({0,1,1,-1});
    while(!q.empty())
    {
        ff now=q.top();
        q.pop();
        if(boo[now.id])
            continue;
        ans+=now.lo;
        if(now.id!=1)
        cs[now.pr].push_back(now.hh);
        boo[now.id]=true;
        for(int i=0;i<g[now.id].size();i++)
        {
            int ne=g[now.id][i];
            int vv=v[now.id][i];
            if(vv<dis1[ne])
            {
                dis1[ne]=vv;
                q.push({vv,ne,now.id,i});
            }
        }
    }
    return;
}
long long S(int now,int kk)
{
    for(int i=0;i<cs[now].size();i++)
    {
        int nex=g[now][cs[now][i]];
        int vo=v[now][cs[now][i]];
        if(a[kk][nex]<vo)
        {
            return S(nex,kk)+vo-a[kk][nex];
        }

        return S(nex,kk);
    }
    return 0;
}
int zzz;
long long mvu;
void SS(int now,long long vu,int kk)
{
    for(int i=0;i<cs[now].size();i++)
    {
        int nex=g[now][cs[now][i]];
        int vo=v[now][cs[now][i]];
        vu+=a[kk][now];
        vu-=a[kk][nex];
        if(a[kk][nex]<vo)
        vu-=vo-a[kk][nex];
        if(a[kk][now]<vo)
        vu+=vo-a[kk][now];
        if(vu>mvu)
        {
            mvu=vu;
            zzz=nex;
        }
        SS(nex,vu,kk);
        vu-=a[kk][now];
        vu+=a[kk][nex];
        if(a[kk][nex]<vo)
        vu+=vo-a[kk][nex];
        if(a[kk][now]<vo)
        vu-=vo-a[kk][now];
    }
}
long long tans=0;
void K(int now,vector<int>cc[],long long ans,int zz)
{
    if(now>k)
        return;
    K(now+1,cc,ans,zz);
    int xia=a[now][zz]+c[now]-S(zz,now);
    zzz=zz;
    mvu=0;
    SS(zz,0,now);
    ans+=xia;
    ans-=mvu;
    tans=min(tans,ans);
}
void KK(int now,int yui)
{
    if(now>k)
        return;
    KK(now+1,yui);
    for(int i=1;i<=n;i++)
    {
        g[i].push_back(n+now);
        g[n+now].push_back(i);
        v[i].push_back(a[now][i]);
        v[n+now].push_back(a[now][i]);
    }
    yui+=c[now];
    ans=yui;
    P();
    tans=fminl(ans,tans);
    KK(now+1,yui);
    for(int i=1;i<=n;i++)
    {
        g[i].pop_back();
        g[n+now].pop_back();
        v[i].pop_back();
        v[n+now].pop_back();
    }
    return;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int n1,n2,n3;
        scanf("\n%d %d %d",&n1,&n2,&n3);
        g[n1].push_back(n2);
        g[n2].push_back(n1);
        v[n1].push_back(n3);
        v[n2].push_back(n3);
    }
    bool flag=true;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0)
                flag=false;
        }
    }
    P();
    tans=ans;
    if(flag)
    {
        long long ttans=tans;
        for(int i=1;i<=k;i++)
            ttans=fminl(ttans,c[i]);
        cout<<ttans;
        return 0;
    }
    if(k<=5)
    {
        KK(1,0);
        cout<<tans;
        return 0;
    }
    K(1,cs,ans,1);
    cout<<tans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Maxn=1e4+10;
const ll inf=1e18;
const int Maxm=1e6+10;
int n,m,k;
struct Edge{
    int u,v;
    ll w;
}vc[Maxm*2],S[Maxm*2];
inline int read()
{
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return w*s;
}

int fa[Maxm];
int cnt[Maxm];
struct Change{
    ll id;
    int ws[Maxm];
}C[11];
ll ans=inf;
int get(int x)
{
    if(fa[x]==x)
    {
        return x;
    }
    return fa[x]=get(fa[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
void work(int status)
{
    ll res=0;
    int nums=n;
    vector<Edge> sv;
    for(int i=0;i<k;i++)
    {
        if(status&(1<<i))
        {
            nums++;
            res+=C[i].id;
            for(int j=1;j<=n;j++)
            {
                sv.push_back((Edge){nums,j,C[i].ws[j]});
            }
        }
    }
    sort(sv.begin(),sv.end(),cmp);
    int id=0;
    int numm=0;
    for(int i=1;i<=m;i++)
    {
        if(id==sv.size())
        {
            S[++numm]=vc[i];
        }else{
            while(id<sv.size() && vc[i].w>sv[id].w)
            {
                S[++numm]=sv[id];
                id++;
            }
            S[++numm]=vc[i];
        }
    }


    int need=nums-1;
    for(int i=1;i<=nums;i++) fa[i]=i,cnt[i]=1;
    for(int i=1;i<=numm;i++)
    {
        int u=S[i].u,v=S[i].v,w=S[i].w;
        int gu=get(u),gv=get(v);
        if(gu==gv) continue;
        need--;
        if(cnt[gu]>cnt[gv]) swap(gu,gv);
        fa[gu]=gv;
        cnt[gv]+=cnt[gu];
        res+=w;
        if(!need) break;
    }

    ans=min(ans,res);
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        u=read(),v=read(),w=(ll)read();
        vc[i]=((Edge){u,v,w});
    }
    bool tag=1;
    sort(vc+1,vc+1+m,cmp);
    for(int i=0;i<k;i++)
    {
        C[i].id=read();
        if(C[i].id!=0)
        {
            tag=0;
        }
        bool flag=0;
        for(int j=1;j<=n;j++)
        {
            int v;
            v=read();
            C[i].ws[j]=v;
            if(v==0) flag=1;
        }
        if(flag==0) tag=0;
    }
    if(tag)
    {
        work((1<<k)-1);
        printf("%lld\n",ans);
        return 0;
    }
    for(int i=0;i<=(1<<k)-1;i++)
    {
        work(i);
    }


    printf("%lld\n",ans);
    return 0;
}

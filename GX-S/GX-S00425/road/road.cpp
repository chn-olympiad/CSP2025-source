#include<bits/stdc++.h>
#define ll long long
#define Max(x,y) (x > y ? x : y)
#define Min(x,y) (x < y ? x : y)
const int M=2e6+6;
const int N=1e5+5;
const ll inf=1e18;
using namespace std;
int n,m,cnt,k;
ll ans=inf,tmp;
int fa[N],C[N],in[N],siz[N];
void init()
{
    for(int i=1;i<=n+10;i++)fa[i]=i,siz[i]=1;
}
int find(int x){fa[x]=(fa[x]==x ? fa[x] : find(fa[x]));return fa[x];}
struct Edge{
    int u,v,val;
    bool operator < (const Edge e)const{
        return val<e.val;
    }
}E[M];
int count_bit(int x)
{
    int res=0;
    while(x)res+=x&1,x>>=1;
    return res;
}
ll count_val(int x)
{
    int j=1;ll res=0;
    for(int i=1;i<=10;i++)in[n+i]=0;
    while(x)
    {
        in[n+j]=(x&1);
        if(in[n+j])
        {
            res+=C[j];
        }
        x>>=1,j++;
    }
    return res;
}
ll pre=inf;
void solve(int idx)
{
    tmp=0;init();
    tmp+=count_val(idx);
    cnt=n+count_bit(idx);
    int tot=1;
    for(int i=1,u,v,w,x,y;i<=m&&tot<cnt;i++)
    {
        u=E[i].u,v=E[i].v,w=E[i].val;
        if(in[u]&&in[v])
        {
            x=find(u),y=find(v);
            if(x!=y)
            {
                if(siz[x]<siz[y]){fa[x]=y;siz[y]+=siz[x];}
                else {fa[y]=x;siz[x]+=siz[y];}
                tot++;tmp+=w;
            }
        }
    }
    ans=Min(ans,tmp);
}
void work()
{
    cin>>n>>m>>k;
    //cout<<(m+n*k)<<"\n";
    for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        E[i]={u,v,w};
    }
    for(int i=1;i<=n;i++)in[i]=1;
    ll sum=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&C[i]);sum+=C[i];
        for(int j=1,x;j<=n;j++)
        {
            scanf("%d",&x);sum+=x;
            E[++m]={n+i,j,x};
        }
    }
    if(!sum)
    {
        printf("%d\n",0);
        return ;
    }
    sort(E+1,E+1+m);
    int IDX=(1<<k);
    for(int idx=0;idx<IDX;idx++)
    {
        solve(idx);
    }

    printf("%lld\n",ans);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    work();
    return 0;
}

#include<bits/stdc++.h>
#define int long long

using namespace std;

const int maxn=1e4,maxk=10,maxm=1e6;
int n,m,k,s,ans=LLONG_MAX;
int mp[maxn][maxn],c[maxk],a[maxk][maxn],father[maxn+maxk];
bool build[maxk];
struct edge
{
    int u,v,w;
}edges[maxm+maxk*maxn];

bool cmp(edge x,edge y)
{
    return x.w<y.w;
}

int find(int x)
{
    if(father[x]==x)return x;
    else return father[x]=find(father[x]);
}

void work()
{
    vector<int> haveedge[maxk];
    int nowans=0;
    for(int i=0;i<n+k;i++)
    {
        father[i]=i;
    }
    for(int i=0;i<k;i++)
    {
        if(build[i])
        {
            nowans+=c[i];
            for(int j=0;j<n;j++)
            {
                edges[s++]=(edge){n+i,j,a[i][j]};
            }
        }
    }
    sort(edges,edges+s,cmp);
    for(int i=0;i<s;i++)
    {
        int u=edges[i].u,v=edges[i].v,w=edges[i].w;
        if(find(u)==find(v))
        {
            continue;
        }
        father[u]=father[v]=min(father[u],father[v]);
        nowans+=w;
        if(u>=n)haveedge[u-n].push_back(w);
    }
    for(int i=0;i<k;i++)
    {
        if(build[i])
        {
            if(haveedge[i].size()<=1)
            {
                nowans-=c[i];
            }
        }
    }
    ans=min(ans,nowans);
}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    while(s<m)
    {
        int u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        if(u<v)swap(u,v);
        mp[u-1][v-1]=w;
        edges[s++]=(edge){u-1,v-1,w};
    }
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&c[i]);
        for(int j=0;j<n;j++)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=0;i<(1<<k);i++)
    {
        s=m;
        int temp=i;
        for(int j=0;j<k;j++)
        {
            build[j]=temp&1;
            temp>>=1;
        }
        work();
    }
    printf("%lld",ans);
    return 0;
}

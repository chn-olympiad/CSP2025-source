#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;

int n,m,k;

int f[10010];
int get(int x)
{
    if (!f[x]) return x;
    return f[x]=get(f[x]);
}

struct edge{
    int u,v,w;
}ed[N];

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

int c[N];

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%lld %lld %lld",&n,&m,&k);
    for (int i=1;i<=m;i++) scanf("%lld %lld %lld",&ed[i].u,&ed[i].v,&ed[i].w);
    for (int i=1;i<=k;i++)
    {
        int x=0;
        scanf("%lld",&x);
        x=0;
        for (int j=1;j<=n;j++){scanf("%lld",&c[j]);if (c[j]==0) x=j;}
        for (int j=1;j<=n;j++)
        {
            if (j==x) continue;
            ed[++m]={x,j,c[j]};
        }
    }
    sort(ed+1,ed+m+1,cmp);

    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int u=ed[i].u,v=ed[i].v,w=ed[i].w;
        if (get(u)==get(v)) continue;
        f[get(u)]=get(v);
        ans+=w;//cout<<i<<" "<<w<<endl;
    }

    printf("%lld\n",ans);

    return 0;
}
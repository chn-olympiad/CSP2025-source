#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4,M=2e6;
ll ans;
int n,m,k,c[N],fa[N];
struct node
{
    int u,v,w;
}s[M];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int fd(int adr)
{
    if(fa[adr]==adr) return adr;
    fa[adr]=fd(fa[adr]);
    return fa[adr];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int cnt=n+k-1,now=1;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        s[i].u=u,s[i].v=v,s[i].w=w;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&c[i]);
        ans+=c[i];
        for(int j=1;j<=n;j++)
        {
            int x;
            scanf("%d",&x);
            s[m+(i-1)*n+j].u=n+i,s[m+(i-1)*n+j].v=j,s[m+(i-1)*n+j].w=x;
        }
    }
    for(int i=1;i<=n+k;i++) fa[i]=i;
    sort(s+1,s+m+n*k+1,cmp);
    while(cnt>0)
    {
        while(fd(s[now].u)==fd(s[now].v)) now++;
        ans+=s[now].w;
        fa[fd(s[now].u)]=s[now].v;
        cnt--,now++;
    }
    printf("%lld\n",ans);
    return 0;
}

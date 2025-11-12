#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,ans=0;
struct node{
    ll u,v,w;
}liu[1000010];
ll read()
{
    ll x=0,y=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')y=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(ll)c;
        x-='0';
        c=getchar();
    }
    return x*y;
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    for(ll i=1;i<=m;i++)
    {
        liu[i].u=read();
        liu[i].v=read();
        liu[i].w=read();
        liu[i+m]=liu[i];
    }
    for(ll liu1,i=1;i<=k;i++)
    {
        liu1=read();
        ll liu2[1010];
        for(ll j=1;j<=n;j++)
            liu2[j]=read();
    }
    sort(liu+1,liu+2*m+1,cmp);
    bool bok[1010];
    memset(bok,false,sizeof(bok));
    bok[1]=true;
    for(ll i=2;i<=n;i++)
    {
        ll j=1;
        for(;j<=m+m;j++)
            if(bok[liu[j].u]&&(!bok[liu[j].v]))break;
        bok[liu[j].v]=true;
        ans+=liu[j].w;
    }
    printf("%lld\n",ans);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
inline int read()
{
    int x=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    return x*f;
}
struct road
{
    int u,v,w;
}e[1100005];
int n,m,k,t,f[10015],c[15],b[33][6]={{0,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,1,1,0,0,0},{0,0,0,1,0,0},{0,1,0,1,0,0},{0,0,1,1,0,0},{0,1,1,1,0,0},{0,0,0,0,1,0},{0,1,0,0,1,0},{0,0,1,0,1,0},{0,1,1,0,1,0},{0,0,0,1,1,0},{0,1,0,1,1,0},{0,0,1,1,1,0},{0,1,1,1,1,0},{0,0,0,0,0,1},{0,1,0,0,0,1},{0,0,1,0,0,1},{0,1,1,0,0,1},{0,0,0,1,0,1},{0,1,0,1,0,1},{0,0,1,1,0,1},{0,1,1,1,0,1},{0,0,0,0,1,1},{0,1,0,0,1,1},{0,0,1,0,1,1},{0,1,1,0,1,1},{0,0,0,1,1,1},{0,1,0,1,1,1},{0,0,1,1,1,1},{0,1,1,1,1,1}};
long long as=9000000000000000000;
bool cmp(road aa,road bb)
{
    return aa.w<bb.w;
}
int find(int x)
{
    if(x==f[x])return x;
    else return f[x]=find(f[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j;
    n=read();m=read();k=read();
    for(i=1;i<=m;i++)
    {
        int x=read(),y=read(),z=read();
        e[++t].u=x;e[t].v=y;e[t].w=z;
    }
    for(i=1;i<=k;i++)
    {
        c[i]=read();
        for(j=1;j<=n;j++)
        {
            e[++t].u=j;e[t].v=n+i;e[t].w=read();
        }
    }
    sort(e+1,e+t+1,cmp);
    for(j=0;j<(1<<k);j++)
    {
        long long s=0;
        for(i=1;i<=n+k;i++)f[i]=i;
        int vv[15];memset(vv,0,sizeof(vv));
        for(i=1;i<=k;i++)
            if(b[j][i]==1)
                s+=c[i];
        for(i=1;i<=t;i++)
        {
            if(e[i].v>n){if(b[j][e[i].v-n]==0)continue;}
            //cout<<i<<" u"<<e[i].u<<" "<<f[e[i].u]<<" v"<<e[i].v<<" "<<f[e[i].v]<<endl;
            if(find(e[i].u)!=find(e[i].v))
            {
                f[find(e[i].u)]=find(e[i].v);
                s+=e[i].w;
            }
            //cout<<"s"<<s<<endl;
        }
        as=min(as,s);
    }
    printf("%lld",as);
    return 0;
}

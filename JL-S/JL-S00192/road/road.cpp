#include<bits/stdc++.h>
using namespace std;
struct road
{
    int u;
    int v;
    int w;
    int col;
    friend bool operator < (road a,road b)
    {
        return a.w<b.w;
    }
}r[2200000];
int w[11000];
int f[11000];
int gr(int x)
{
    if(f[x]<0)return x;
    f[x]=gr(f[x]);
    return f[x];
}
bool un(int x,int y)
{
    x=gr(x);
    y=gr(y);
    if(x==y)return false;
    if(f[x]<f[y])
    {
        f[x]+=f[y];
        f[y]=x;
    }
    else
    {
        f[y]+=f[x];
        f[x]=y;
    }
    return true;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,i,j,a,sum,flag;
    long long ans,ans1;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&r[i].u,&r[i].v,&r[i].w);
        r[i].col=0;
    }
    for(i=0,sum=n+1;i<k;i++,sum++)
    {
        scanf("%d",&w[i]);
        for(j=1;j<=n;j++)
        {
            r[m].u=sum;
            r[m].v=j;
            scanf("%d",&r[m].w);
            r[m].col=i+1;
            m++;
        }
    }
    sort(r,r+m);
    ans=0x3f3f3f3f3f3f3f3f;
    for(i=0;i<(1<<k);i++)
    {
        memset(f,-1,sizeof(f));
        ans1=0;
        for(j=0;j<k;j++)
        {
            if(((i>>j)&1)==1)ans1+=w[j];
        }
        flag=1;
        for(j=0;j<m;j++)
        {
            if((r[j].col!=0)&&(((i>>(r[j].col-1))&1)!=1))continue;
            if(un(r[j].u,r[j].v))ans1+=r[j].w;
            if(ans1>=ans)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)ans=min(ans,ans1);
    }
    printf("%lld",ans);
    return 0;
}

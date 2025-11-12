#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u,v;
    long long w;
    bool operator <(const node &x)const
    {
        return w<x.w;
    }
}s1[1000005],s2[100005];
int n,m,k,pa[10005];
long long a[15][10005],c[15];
int get_fa(int x)
{
    return pa[x]==x?x:pa[x]=get_fa(pa[x]);
}
void solve1()
{
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            s2[(i-1)*n+j]={n+i,j,a[i][j]};
    sort(s2+1,s2+k*n+1);
    int l=1,r=1,cnt=0;
    long long sum=0;
    while(cnt<n+k-1)
    {
        node tmp;
        if(l>m)
        {
            tmp=s2[r];
            r++;
        }
        else if(r>k*n)
        {
            tmp=s1[l];
            l++;
        }
        else if(s1[l].w<s2[r].w)
        {
            tmp=s1[l];
            l++;
        }
        else
        {
            tmp=s2[r];
            r++;
        }
        int u=tmp.u,v=tmp.v,uu=get_fa(u),vv=get_fa(v);
        long long w=tmp.w;
        if(uu!=vv)
        {
            cnt++;
            sum+=w;
            pa[uu]=vv;
        }
    }
    printf("%lld\n",sum);
    exit(0);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n+k;i++)
        pa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        s1[i]={u,v,w};
    }
    sort(s1+1,s1+m+1);
    int flag=1;
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        if(c[i]!=0)
            flag=0;
        int f=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&a[i][j]);
            if(a[i][j]==0)
                f=1;
        }
        if(f==0)
            flag=0;
    }
    if(flag)
        solve1();
    long long ans=1e18;
    for(int s=0;s<(1<<k);s++)
    {
        int num=0,l=1,r=1,cnt=0;
        long long sum=0;
        for(int i=0;i<k;i++)
            if(s&(1<<i))
            {
                num++;
                sum+=c[i+1];
                for(int j=1;j<=n;j++)
                    s2[i*n+j]={n+i+1,j,a[i+1][j]};
            }
        sort(s2+1,s2+num*n+1);
        for(int i=1;i<=n+k;i++)
            pa[i]=i;
        while(cnt<n+num-1)
        {
            node tmp;
            if(l>m)
            {
                tmp=s2[r];
                r++;
            }
            else if(r>num*n)
            {
                tmp=s1[l];
                l++;
            }
            else if(s1[l].w<s2[r].w)
            {
                tmp=s1[l];
                l++;
            }
            else
            {
                tmp=s2[r];
                r++;
            }
            int u=tmp.u,v=tmp.v,uu=get_fa(u),vv=get_fa(v);
            long long w=tmp.w;
            if(uu!=vv)
            {
                cnt++;
                sum+=w;
                pa[uu]=vv;
            }
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}

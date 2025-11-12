#include<bits/stdc++.h>
using namespace std;
struct St{
    int x,y;
    long long z;
    bool operator<(const St &B)const{
        return z<B.z;
    }
}edge[2000005],edge1[2000005];
int c[15];
long long a[15][20005];
int fa[20005];
inline int fd(int now)
{
    if(fa[now]==now)return now;
    return fa[now]=fd(fa[now]);
}
int n,m,k;
long long ans=0;
int cnt[20005];
long long tmp[20005];
int read()
{
    char c;
    int now=0;
    while(c=getchar())
    {
        if(c<'0'||c>'9')break;
        now=now*10+c-'0';
    }
    return now;
}
inline St make_edge(int x,int y,long long z)
{
    St ans;
    ans.x=x;ans.y=y;ans.z=z;
    return ans;
}
int bj[15];
inline long long dfs(int now)
{
    if(now==k+1)
    {
        for(int i=1;i<=m;i++)
        {
            edge1[i]=edge[i];
        }
        int len=m,ct=n;
        long long tmppp=0;
        for(int i=1;i<=k;i++)
        {
            if(bj[i])
            {
                tmppp+=c[i];
                ct++;
                for(int j=1;j<=n;j++)
                {
                    edge1[++len]=make_edge(i+n,j,a[i][j]);
                }
            }
        }
        sort(edge1+1,edge1+len+1);
        for(int i=1;i<=n;i++)fa[i]=i;
        long long ans1=0;
        int lf,ri,cnt1=0;
        for(int i=1;i<=len;i++)
        {
            lf=fd(edge1[i].x);ri=fd(edge1[i].y);
            if(lf==ri)continue;
            ans1+=edge1[i].z;
            fa[lf]=ri;
            cnt1++;
            if(cnt1==ct-1)break;
        }
        //printf("%lld\n\n",ans1);
        return ans1+tmppp;
    }
    long long nans=0;
    bj[now]=0;
    nans=dfs(now+1);
    bj[now]=1;
    return min(nans,dfs(now+1));
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int tmpp;
    n=read();m=read();k=read();tmpp=m;
    for(register int i=1;i<=m;i++)
    {
        edge[i].x=read();
        edge[i].y=read();
        edge[i].z=read();
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    bool op=1;
    for(register int i=1;i<=k;i++)
    {
        fa[i+n]=i+n;
        c[i]=read();
        op&=(c[i]==0);
        for(register int j=1;j<=n;j++)
        {
            a[i][j]=read();
            edge[++m].x=n+i;edge[m].y=j;edge[m].z=a[i][j];
        }
    }
    if(!op&&k)
    {
        m=tmpp;
        printf("%lld",dfs(1));
        return 0;
    }
    n=n+k;
    int lf,ri,cnt1=0;
    sort(edge+1,edge+m+1);
    for(register int i=1;i<=m;i++)
    {
        lf=fd(edge[i].x);ri=fd(edge[i].y);
        if(lf==ri)continue;
        cnt[edge[i].x]++;cnt[edge[i].y]++;
        tmp[edge[i].x]+=edge[i].z;
        tmp[edge[i].y]+=edge[i].z;
        //printf("%d %d %d\n",edge[i].x,edge[i].y,edge[i].z);
        ans+=edge[i].z;
        fa[lf]=ri;
        cnt1++;
        if(cnt1==n-1)break;
    }
    //printf("%lld %d\n",ans,n-1);
    for(register int i=n-k+1;i<=n;i++)
    {
        if(cnt[i]==1)
        {
            ans-=tmp[i];
        }
    }
    printf("%lld\n",ans);
}

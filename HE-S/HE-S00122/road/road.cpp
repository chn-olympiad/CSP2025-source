#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,cnt;
struct edge{
    int x,y,w;
}e[1200005];
int a[15][10005],c[15];
int fa[10050],du[10050];
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void work1()//k=0 kruscal
{
    for(int i=1;i<=n+k;i++) fa[i]=i;
    sort(e+1,e+1+m,[](edge a,edge b){return a.w<b.w;});
    int num=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        int fx=find(e[i].x),fy=find(e[i].y);
        if(fx==fy) continue;
        fa[fx]=fy;
        num++;
        ans+=e[i].w;
        if(num==n-1) break;
    }
    cout<<ans<<'\n';
    return ;
}
void work2()
{
    int ans=1e18,res=0,num=0,tot=0;
    sort(e+1,e+1+cnt,[](edge a,edge b){return a.w<b.w;});
    for(int i=0;i<(1<<k)-1;i++)
    {
        res=num=0;
        tot=n;
        for(int j=1;j<=n+k;j++) fa[j]=j;
        for(int j=0;j<k;j++) if((i>>j)&1) res+=c[j+1],tot++;
        for(int j=1;j<=cnt;j++)
        {
            int fx=find(e[j].x),fy=find(e[j].y);
            if(e[j].x>n&&(i>>(e[j].x-n-1)&1)!=1) continue;
            if(fx==fy) continue;
            fa[fx]=fy;
            num++;
            res+=e[j].w;
            if(num==tot-1) break;
        }
        ans=min(res,ans);
    }
    cout<<ans<<'\n';
    return ;
}
signed main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>e[i].x>>e[i].y>>e[i].w;
    cnt=m;
    if(k==0)
    {
        work1();
        return 0;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            e[++cnt]={i+n,j,a[i][j]};
        }
    }
    work2();
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/

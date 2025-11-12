#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int u,v,w;
}a[1000010],b[1300010];
int n,m,k,fa[10010],c[30],x[30][10010];
long long ans=2e18;
bool f[20];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void check()
{
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++) b[i]=a[i];
    int cnt=m,cnt1=n,cnt2=0;
    long long sum=0;
    for(int i=1;i<=k;i++)
    {
        if(f[i])
        {
            cnt1++;
            sum+=c[i];
            for(int j=1;j<=n;j++)
            {
                b[++cnt].u=cnt1;
                b[cnt].v=j;
                b[cnt].w=x[i][j];
            }
        }
    }
    sort(b+1,b+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        int y=find(b[i].u),z=find(b[i].v);
        if(y!=z)
        {
            cnt2++;
            sum+=b[i].w;
            fa[z]=y;
        }
        if(cnt1==cnt2+1) break;
    }
    ans=min(ans,sum);
}
void dfs(int step)
{
    if(step>k)
    {
        check();
        return;
    }
    f[step]=1;
    dfs(step+1);
    f[step]=0;
    dfs(step+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    bool flag=0;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        if(c[i]!=0) flag=1;
        for(int j=1;j<=n;j++) cin>>x[i][j];
    }
    if(flag==0)
    {
        for(int i=1;i<=k;i++) f[i]=1;
        check();
        cout<<ans;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}

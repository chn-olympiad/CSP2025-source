#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,fa[10015],sz[10015],cst[15];
ll ans=1e18,now=0,us[15];
int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    if(sz[find(x)]>sz[find(y)])
    {
        sz[fa[x]]+=sz[fa[y]];
        fa[fa[y]]=fa[x];
    }
    else
    {
        sz[fa[y]]+=sz[fa[x]];
        fa[fa[x]]=fa[y];
    }
    return;
}
struct node
{
    int u,v,w;
}p[1000005],q[15][10005],no[15][200005];
bool cmp(node x,node y)
{
    return x.w<y.w;
}
void dfs(int x,ll val,int mm)
{
    int l1=1,l2=1;
    if(x==k+1)
    {
        now=0;
        for(int i=1;i<=n+k;i++)
        {
            sz[i]=1;
            fa[i]=i;
        }
        for(int i=1;i<=mm;i++)
        {
            if(find(no[k][i].u)!=find(no[k][i].v))
            {
                merge(no[k][i].u,no[k][i].v);
                now+=no[k][i].w;
            }
        }
        ans=min(ans,now+val);
        return;
    }
    us[x]=0;
    for(int i=1;i<=mm;i++)
    {
        no[x][i]=no[x-1][i];
    }
    dfs(x+1,val,mm);
    us[x]=1;
    for(int i=1;i<=mm+n;i++)
    {
        if(l1>mm)
            no[x][i]=q[x][l2++];
        else
        {
            if(l2>n)
                no[x][i]=no[x-1][l1++];
            else
            {
                if(q[x][l2].w<no[x-1][l1].w)
                    no[x][i]=q[x][l2++];
                else
                    no[x][i]=no[x-1][l1++];
            }
        }
    }
    dfs(x+1,val+cst[x],mm+n);
    us[x]=0;
    return;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,mm=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>p[i].u>>p[i].v>>p[i].w;
    }
    sort(p+1,p+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(find(p[i].u)!=find(p[i].v))
        {
            no[0][++mm]=p[i];
        //    cout<<p[i].u<<" "<<p[i].v<<"\n";
            merge(p[i].u,p[i].v);
        }
    }
    for(int i=1;i<=k;i++)
    {
        cin>>cst[i];
        for(int j=1;j<=n;j++)
        {
            cin>>q[i][j].w;
            q[i][j].u=n+i;
            q[i][j].v=j;
        }
        sort(q[i]+1,q[i]+n+1,cmp);
    }
    dfs(1,0,mm);
    cout<<ans;
    return 0;
}

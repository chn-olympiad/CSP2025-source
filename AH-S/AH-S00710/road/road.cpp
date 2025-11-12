#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k;
long long china=0x3f3f3f3f;
struct node
{
    long long nx,v;
};
struct edge
{
    int a,b;
    long long val;
};
edge rel[1000005];
int c[10005];
long long ans;
long long t[15][10005];
int fa[10005];
bool f[1000005];
bool gg[1000005];
bool cmp(edge x,edge y)
{
    return x.val<y.val;
}
int b_find(int x)
{
    if(x==fa[x])
    {
        return x;
    }
    int e=b_find(fa[x]);
    fa[x]=e;
    return e;
}
bool b_ser(int x,int y)
{
    if(b_find(x)==b_find(y))
    {
        return true;
    }
    return false;
}
void man()
{
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(b_find(i)!=b_find(1))
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        return ;
    }
    for(int i=1;i<=m;i++)
    {
        if(f[i]==0)
        {
            if(!b_ser(rel[i].a,rel[i].b))
            {
                long long minn=rel[i].val;
                for(int j=1;j<=k;j++)
                {
                    if(gg[j]==1)
                    {
                        minn=min(minn,t[j][rel[i].a]+t[j][rel[i].b]);
                    }
                }
                fa[b_find(rel[i].a)]=b_find(rel[i].b);
                ans+=minn;
            }
            f[i]=1;
        }
    }
    man();
}
void dfs(int x)
{
    if(x==k+1)
    {
        long long z=ans;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
        man();
        china=min(china,ans);
        ans=z;

        return ;
    }
    gg[x]=1;
    ans+=c[x];
    dfs(x+1);
    gg[x]=0;
    ans-=c[x];
    dfs(x+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1,u,v,c;i<=m;i++)
    {
        cin>>u>>v>>c;
        rel[i]=((edge){u,v,c});
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            cin>>t[i][j];
        }
    }
    sort(rel+1,rel+1+m,cmp);
    dfs(1);
    ans=0;
    man();
    cout<<min(china,ans)<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

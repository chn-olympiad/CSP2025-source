#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k;
int fa[10005];
struct edge
{
    int u,v,w;
}a[1000005];
void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(x); 
}
bool unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y) return false;
    fa[y]=x;
    return true;
}
bool cmp(edge x,edge y){return x.w<y.w;}
long long ans;
int main()
{
    freopen("rode.in","r",stdin);
    freopen("rode.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=k;i++)
    {
        int tmp;
        for(int j=0;j<=n;j++) cin>>tmp;
    }
    init();
    for(int i=1;i<=m;i++)
    {
        if(unite(a[i].u,a[i].v))
        {
            n--;
            ans+=a[i].w;
        }
        if(n==1) break;
    }
    cout<<ans;
    return 0;
}

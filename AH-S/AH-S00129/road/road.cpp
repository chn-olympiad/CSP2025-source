#include<bits/stdc++.h>
using namespace std;
struct stu
{
    int x,y,w;
}v[5005*5005];
int n,m,k;
int fa[10001];
void init()
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    return ;
}
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int same(int x,int y)
{
    return find(x)==find(y);
}
void gather(int x,int y)
{
    fa[find(x)]=y;
    return ;
}
bool cmp(stu x,stu y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++)
    {
        cin>>v[i].x>>v[i].y>>v[i].w;
    }
    int cnt=m;
    for(int i=1;i<=k;i++)
    {
        int x;
        int a[100001];
        cin>>x;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            for(int p=j-1;p>=1;p--)
            {
                v[++cnt].x=j;
                v[cnt].y=p;
                v[cnt].w=a[j]+a[p]+x;
            }
        }
    }
    sort(v+1,v+cnt+1,cmp);
    int sum=0,res=0;
    for(int i=1;i<=cnt;i++)
    {
        if(sum==n-1)
        {
            break;
        }
        if(!same(v[i].x,v[i].y))
        {
            sum++;
            gather(v[i].x,v[i].y);
            res+=v[i].w;
        }
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    int u,v,w;
}p[1050010];
int n,m,k;
int fa[10010];
int ans;
int find(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
    return x;
}
bool cmp(node x,node y)
{
    return x.w<y.w;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i].u>>p[i].v>>p[i].w;
    }
    int tmp,cnt=1,cntt=1;
    for(int i=1;i<=k;i++)
    {
        cin>>tmp;
        p[m+cnt].u=n+cntt;
        cntt++;
        p[m+cnt].v=n+cntt;
        p[m+cnt].w=tmp;
        cnt++;
        for(int j=1;j<=n;j++)
        {
            cin>>tmp;
            p[m+cnt].u=n+cntt;
            p[m+cnt].v=j;
            p[m+cnt].w=tmp;
            cnt++;
        }
    }
    int N=n+k*2;
    for(int i=1;i<=N;i++)
    {
        fa[i]=i;
    }
    sort(p+1,p+1+N,cmp);
    int M=N-1;
    for(int i=1;i<=m+cnt&&M>0;i++)
    {
        int x=p[i].u,y=p[i].v;
        if(find(x)!=find(y))
        {
            fa[x]=find(y);
            ans+=p[i].w;
            M--;
        }
    }
    cout<<ans;
    return 0;
}

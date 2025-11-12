#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
struct node
{
    long long v,w;
};
long long n,m,k,u,v,w,c[15],a[15][10005];
vector<node>g[10005];
bool flag=true;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;++i)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u].push_back(node{v.w});
        g[v].push_back(node{u.w});
    }
    for(int i=1;i<=k;++i)
    {
        scanf("%lld",&c[i]);
        if(c[i]!=0)
            flag=false;
        for(int j=1;j<=n;++j)
        {
            scanf("%lld",&a[i][j]);
            if(c[i]!=0)
                flag=false;
        }
    }
    if(flag)
    {
        printf("0\n");
        return 0;
    }
    return 0;
}

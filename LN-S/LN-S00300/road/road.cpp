#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
    int w;
}a[1000006];
int cmp(node r,node t)
{
    return r.w<t.w;
}
int n,m,k,ans,val;
bool flag[1000006];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;i++)
        {
            int p;
            scanf("%d",&p);
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(!flag[a[i].x]||!flag[a[i].y])
        {
            val+=a[i].w;
            if(!flag[a[i].x])
            {
                ans++;
                flag[a[i].x]=1;
            }
            if(!flag[a[i].y])
            {
                ans++;
                flag[a[i].y]=1;
            }
            if(ans==n)
            {
                printf("%d",val);
                return 0;
            }
        }
    }
    return 0;
}

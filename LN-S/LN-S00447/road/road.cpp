#include<bits/stdc++.h>
using namespace std;
struct road
{
    int u,v,w;
}r[1100005];
int n,m,k;
bool map1[10005][10005];
bool cmp(road a,road b)
{
    if(a.w<b.w)return 1;
    return 0;
}
set<int>s;
void insert1(int p)
{
    for(int i=1;i<=n;i++)
    {
        if(map1[i][p])
        {
            if(s.size()!=n)
            {
                s.insert(i);
                insert1(i);
            }
            else return;
        }
    }
}
bool check(int p)
{
    s.insert(p);
    insert1(p);
    if(s.size()==n)return 1;
    else return 0;
}
int f(int i)
{
    int tmp=1;
    while(i--)tmp*=2;
    return tmp;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d %d %d",&a,&b,&r[i].w);
        r[i].u=min(a,b);
        r[i].v=max(a,b);
    }
    if(k!=0)
    {
        int c=0,a=0;
        for(int i=1;i<=k;i++)
        {
            cin>>c;
            for(int j=1;j<=n;j++)
            {
                cin>>a;
            }
        }
    }
    sort(r+1,r+1+n,cmp);
    for(int i=1;i<=m;i++)
    {
        printf("%d %d %d\n",r[i].u,r[i].v,r[i].w);
    }
    int ans=0x3f3f3f3f;
    for(int j=1;j<=pow(2,m);j++)
    {
        int tmp=0;
        for(int i=1;i<=m;i++)
        {
            if(j%f(i))
            {
                 map1[r[i].u][r[i].v]=1;
                 map1[r[i].v][r[i].u]=1;
                 tmp+=r[i].w;
            }
        }
        if(tmp>=ans)continue;
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(!check(i))
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            ans=tmp;
        }
    }
    printf("%d",ans);
}

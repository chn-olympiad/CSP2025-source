#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15][10005],fa[1000005],mp[1005][1005];
struct node
{
    long long x,y,z;
}stu[20000005];
int fin(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=fin(fa[x]);
}
bool cmp(node a,node b)
{
    return a.z<b.z;
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
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&stu[i].x);
        scanf("%lld",&stu[i].y);
        scanf("%lld",&stu[i].z);
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%lld",&c[i][0]);
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&c[i][j]);
        }
    }
    memset(mp,0x7f,sizeof(mp));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int l=j+1;l<=n;l++)
            {
                mp[j][l]=mp[l][j]=min(mp[j][l],c[i][0]+c[i][j]+c[i][l]);
                m++;
                stu[m].x=j,stu[m].y=l,stu[m].z=mp[j][l];
                m++;
                stu[m].x=l,stu[m].y=j,stu[m].z=mp[j][l];
            }
        }
    }
    long long s=0,ans=0;
    sort(stu+1,stu+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        if(s==n-1)break;
        int r1=fin(stu[i].x),r2=fin(stu[i].y);
        if(r1!=r2)
        {
            fa[r1]=r2;
            s++;
            long long minn=stu[i].z;
            ans+=minn;
        }
    }
    cout<<ans;
    return 0;
}

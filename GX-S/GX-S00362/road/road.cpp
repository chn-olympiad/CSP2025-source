#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#define int long long
using namespace std;
int n,m,k;
int c[100];
int ans;
int vis[1000010];
struct nx1
{
    int x,y,z;
}a[1000100];
struct nx
{
   int nxt,to;
   int val;
}e[1000100*4];
int cnt,head[1000100];
void add(int u,int v,int val)
{
    e[++cnt].to=v;
    e[cnt].val=val;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
bool gz(nx1 x1,nx1 x2)
{
    return x1.z>x2.z;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
        ans+=a[i].z;
        vis[a[i].x]++,vis[a[i].y]++;
    }
    if (m>n-1)
    {
        int flag=m-n+1;
        sort(a+1,a+m+1,gz);
        for (int i=1;i<=m;i++)
        {
               if (flag==0) break;
               if (vis[a[i].x]!=1 && vis[a[i].y]!=1)
                  ans-=a[i].z,flag--;
        }   
    }
    if (k==0) {cout<<ans;return 0;}

    return 0;
}



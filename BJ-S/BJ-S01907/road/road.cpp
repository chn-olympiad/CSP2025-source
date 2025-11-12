#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct ro
{
    int u,v1,w;
    void read()
    {
        cin>>u>>v1>>w;
    }
};
struct vi
{
    int c;
    int a[100010];
};
ro r[100010];
vi v[100010];
int a1[100010];
bool cmp(ro x,ro y)
{
    return x.w<y.w;
}
bool cmp1(vi x,vi y)
{
    return x.c<y.c;
}
bool cmp2(int x,int y)
{
    return x<y;
}
bool check(int a1[])
{
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if(a1[i]>0) cnt++;
    }
    return cnt>2;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) r[i].read();
    for (int i=1;i<=k;i++)
    {
        cin>>v[i].c;
        for (int j=1;j<=n;j++)
        {
            cin>>v[i].a[i];
        }
    }
    sort(r+1,r+m+1,cmp);
    sort(v+1,v+k+1,cmp1);
    ll cost=0;
    for (int i=1;i<=m;i++)
    {
        a1[r[i].u]++;
        a1[r[i].v1]++;
        if(check(a1)) break;
        else cost+=r[i].w;
    }
    for (int i=1;i<=k;i++)
        sort(v[i].a+1,v[i].a+n+1,cmp2);
    cost=cost+v[1].a[1]+v[1].a[2];
    cout<<cost<<endl;
    return 0;
}
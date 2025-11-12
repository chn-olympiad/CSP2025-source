#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,mx;
long long e[10005][10005];
struct edge
{
    long long u,v,w;
} a[1000005];
struct town
{
    long long c,s[10005];
} b[15];
inline int cmp(edge a,edge b)
{
    return a.w<b.w;
}
inline int cmp2(town a,town b)
{
    return a.c<b.c;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    int flag=0;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1; i<=k; i++)
    {
        cin>>b[i].c;
        if(b[i].c!=0)flag=1;
        for(int j=1; j<=n; j++)
        {
            cin>>b[i].s[j];
            if(b[i].s[j]!=0)flag=1;
        }
    }
    if(!flag)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1; i<=n-1; i++)
    {
        ans+=a[i].w;
    }
    cout<<ans<<endl;
    return 0;
}

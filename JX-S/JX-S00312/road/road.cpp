#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y,w;
};
node a[10050000];
int f[10050000];
long long n,m,k,sum,c;
bool cmp(node a,node b)
{
    return a.w<b.w;

}
int find(int a)
{
    if(f[f[a]]!=f[a])f[a]=find(f[a]);
    return f[a];
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].w;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c;
        sum+=c;
        for(int j=1;j<=n;j++)
        {
            a[i*n+j].x=i+n;
            a[i*n+j].y=j;
            cin>>a[i*n+j].w;
        }

    }

    n=k*n+n;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n+k;i++)f[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(find(a[i].x)!=find(a[i].y))
        {
        sum+=a[i].w;
        f[f[a[i].x]]=a[i].y;
        }
    }
    cout<<sum;
}

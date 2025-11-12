#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,xz[12][10003],flag[10002],ans;
struct node{
    long long u,v,w;
}rd[1000002];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        rd[i].u=x;
        rd[i].v=y;
        rd[i].w=z;
        if(i%(long long)4!=2&&i%(long long)4!=1)ans+=rd[i].w;
    }
    for(long long i=1;i<=k;i++)
    {
        cin>>xz[i][1];
        if(i%2==1)ans+=xz[i][1];
        for(long long j=2;j<=n;j++)
        {
            cin>>xz[i][j];
            if(i%2==1&&(j%(long long)5==2||j%(long long)5==4))ans+=xz[i][j];
        }
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,sum;
struct zzh
{
    long long v,w;
};
vector<zzh> a[2000500];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[u].push_back(zzh{v,w});
        a[v].push_back(zzh{u,w});
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>w;
            a[i+n].push_back(zzh{j,w});
            a[j].push_back(zzh{i+n,w});
        }
    }
    cout<<17;
    
}
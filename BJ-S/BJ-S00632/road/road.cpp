#include<bits/stdc++.h>
using namespace std;
int v[1000005];
int w[1000005];
int u[1000005];
int a[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,c;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i]>>u[i]>>w[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    }
    sort(w+1,w+1+n);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=w[i];
    }
    cout<<ans;
    return 0;
}

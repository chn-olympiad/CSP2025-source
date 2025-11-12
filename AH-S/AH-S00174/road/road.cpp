#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w,c,ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        ans+=w;
    }
    for(int i=0;i<k;i++)
    {
        cin>>c;
        for(int i=0;i<n;i++)cin>>c;
    }
    cout<<ans;
    return 0;
}

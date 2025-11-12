#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        ans+=z;
    }
    cout<<ans<<endl;
    return 0;
}
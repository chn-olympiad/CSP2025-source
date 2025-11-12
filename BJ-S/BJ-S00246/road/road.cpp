#include<bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        ans+=z;
    }
    cout<<ans;
    return 0;
}

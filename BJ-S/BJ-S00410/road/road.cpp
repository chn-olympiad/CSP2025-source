#include<bits/stdc++.h>
using namespace std;
int n,m,k,r[1000005][10],k1[15][10],ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>r[i][1]>>r[i][2]>>r[i][3];
        ans+=r[i][3];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>k1[i][1]>>k1[i][2]>>k1[i][3]>>k1[i][4];
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005],c[1000005],JJ[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int ans=0;
    int ans2=0;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        ans+=w[i];
    }
    int tmp;
    for(int i=0;i<k;i++)
    {
        cin>>c[i];
        JJ[i]+=c[i];
        for(int x=0;x<n;x++)
        {
            cin>>tmp;
            JJ[i]+=tmp;
        }
    }
    sort(JJ,JJ+k);
    cout<<min(ans,JJ[0]);
    return 0;
}

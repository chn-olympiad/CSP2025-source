#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef pair<int,int> pii;
vector<pii> g[N];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ans+=w;
    }

    for(int i=1;i<=k;i++)
    {
        int res=0;
        int c;
        cin>>c;
        for(int j=1;j<=n;j++)
        {
            int u;
            cin>>u;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> t[10005];
int n,m,k,c[15],ans,a[12][10005];
bool b[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        t[u].push_back(w);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<t[i].size();j++)
        {
            if(b[j]==1)
                continue;
            ans+=t[i][j];
            b[j]=1;
        }
    }
    cout<<ans;
}

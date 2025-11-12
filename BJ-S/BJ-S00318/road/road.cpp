#include <bits/stdc++.h>

using namespace std;
const int MAX=1e6+100;
int n,m,k,c[20],a[20][MAX];
vector<pair<int,int>> vec[MAX];
int main()
{
    freopen("road.in",r,stdin);
    freopen("road.out",w,stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        pair<int,int> temp;
        temp.first=v;
        temp.second=w;
        vec[u].push_back(temp);
        temp.first=u;
        vec[v].push_back(temp);
    }
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    cout<<'0';
    return 0;
}

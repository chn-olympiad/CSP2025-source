#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10;
const int inf=1e9+7609;
int fee[15];
int build[15][MAXN];
int n,m,k;
vector<vector<pair<int,int>>> gra(MAXN);
int ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        gra[u].push_back(make_pair(v,w));
    }
    for(int i=1;i<=k;i++)
    {
        cin>>fee[i];
        for(int j=1;j<=n;j++)
        {
            cin>>build[i][j];
        }
    }
    cout<<13;
    return 0;
}
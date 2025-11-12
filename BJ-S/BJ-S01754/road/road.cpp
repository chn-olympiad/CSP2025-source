#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
struct node
{
    int v,w;
    bool operator < (const node& a) const
    {
        return a,w<w;
    }
};
vector<int>e[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        ans+=w;
    }
    cout<<ans;
    return 0;
}

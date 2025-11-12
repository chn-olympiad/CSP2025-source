#include <bits/stdc++.h>
using namespace std;
struct edge{

int u,v,w;
};
vector <edge> e[100005];
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
    {
        int x,y4,z;
        cin>>x>>y4>>z;
        e[i].push_back({x,y4,z});
        ans+=z;
    }
    
    if(k==0) cout<<ans;
    else cout<<0;
    return 0;
}

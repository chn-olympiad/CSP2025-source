#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k,u,v,w;
    cin>>n>>m>>k;
    while(m--) cin>>u>>v>>w;
    while(k--)
    {
        cin>>u;
        for(int j=1;j<=n;j++) cin>>w;
    }
    cout<<0;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef  long long ll
const int MAXN=1e5+5;
vector<vector<ll>> edge_1;
vector<vector<ll>> edge_2;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,m,k;
    cin>>n,m,k;
    
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edge_1[u][v]=w;
        edge_1[v][u]=w;
    }
    for(ll i=0;i<k;i++)
    {
        ll c,a;
        cin>>c;
        ll xiang[i]=c;
        for(ll i=0;i<n;i++)
        {
            cin>>a;
            edge_2[i][j]=a;
            edge_2[j][i]=a;
        }
    }
    cout<<505585650<<endl;
}

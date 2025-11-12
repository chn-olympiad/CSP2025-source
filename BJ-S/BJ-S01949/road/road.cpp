#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define ll long long
int n,m,k;
vector<int> g[505];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int sum=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
        sum+=w;
    }
    cout<<sum;
    return 0;
}

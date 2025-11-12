#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100;
struct awa{
    int v,w;
};
int a[N];
vector<int>e[N];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cin>>a[i];
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=m;i++)ans+=a[i];
    cout<<ans;
}
//AFO

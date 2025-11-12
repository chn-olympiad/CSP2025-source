#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],w[1000010],v[1000010],c[10010],c1[10010];

int main()
{   freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=n+1;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n+1;i++){
        cin>>c1[i];
    }
    return 0;
}

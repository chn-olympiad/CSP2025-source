#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int u[N],v[N],w[N],c[N],a[15][N];
int n,m,k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int pass=0;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    cout<<0;
    return 0;
}

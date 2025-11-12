#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,k;
int u[maxn],v[maxn],w[maxn],c[10][maxn];
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        ans+=w[i];
    }
    cout<<ans;
return 0;
}

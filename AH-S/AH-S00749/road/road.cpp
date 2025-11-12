#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long u[1000005],v[1000005],w[1000005];
long long c[15],a[15][10005];
int t;
int ans;
int main (){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int x=1;
    while (k){
        k--;
        cin>>c[x];
        t+=c[x];
        for (int j=1; j<=n; j++){
            cin>>a[x][j];
            t+=a[x][j];
        }
        x++;
    }
    if (t==0) {
        cout <<t;
        return 0;
    }
    sort (w+1,w+1+m);
    for (int i=1; i<m; i++){
        ans+=w[i];
    }
    cout <<ans;
    return 0;
}

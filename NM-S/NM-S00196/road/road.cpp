#include<bits/stdc++.h>
using namespace std;
int n,m,k,c;
long long u[1000000009],v[1000000009],w[1000000009],a[1000000009][1000000009];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=m+1;i<=m+k+1;i++){
            for(int j=1;j<=n;j++){
                cin>>c>>a[j][i];
            }

    }
    for(int i=1;i<=m;i++){
        int ans+=w[i];
    }
    cout<<ans;
    return 0;
    }

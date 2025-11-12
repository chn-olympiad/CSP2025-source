#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int c[100001];
int w[100001];
int ans=0;
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        w[i]=1e18;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int op;
            cin>>op;
            w[j]=min(op,w[j]);
        }
    }
    for(int i=1;i<=n;i++){
        ans+=w[i];
    }
    cout<<ans<<endl;
    return 0;
}
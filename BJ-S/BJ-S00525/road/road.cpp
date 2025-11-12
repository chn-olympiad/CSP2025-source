#include <bits/stdc++.h>
using namespace std;
int n,m,k;
long long u,v,l;
long long c,a;
long long ans=1e18,res;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>u>>v>>l;
    for(int i=1;i<=k;++i){
        cin>>c;
        res=0;
        for(int j=1;j<=n;++j){
            cin>>a;
            res+=a;
        }
        ans=min(ans,res+c);

    }
    cout<<ans;
    return 0;
}

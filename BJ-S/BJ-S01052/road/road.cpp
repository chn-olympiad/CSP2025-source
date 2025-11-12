#include<bits/stdc++.h>
#define ll long long
ll n,m,q,ans;
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>q;
    for(ll i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ans+=w;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,a,b;
long long ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        ans+=w;
    }
    for(int i=1;i<=k;i++)cin>>u>>v>>w>>a>>b;
    cout<<ans;
    return 0;
}

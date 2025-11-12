#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u[m],v[m],w[m];
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int ls[n+1];
    long long int ans=0;
    for(int i=0;i<=n;i++){
        cin>>ls[i];
        ans+=ls[i];
    }
    cout<<ans;

return 0;
}
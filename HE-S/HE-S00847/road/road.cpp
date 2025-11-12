#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int u[100005],v[100005],w[100005];
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans+=w[i];
    }
    cout<<ans/2+2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

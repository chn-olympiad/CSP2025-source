#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ans+=w;
    }for(int i=0;i<k;i++){
        int c[10001];
        for(int j=0;j<n;j++)cin>>c[j];
    }cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
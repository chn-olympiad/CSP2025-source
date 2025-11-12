#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","r",stdout);
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    int arr[1000000];
    for(int i=0;i<1000000;i++){
        arr[i]=2e9;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr[v]=min(arr[v],w);
        arr[u]=min(arr[u],w);
    }
    for(int i=1;i<=n;i++){
        ans+=arr[i];
    }
    cout<<ans;
    return 0;
}

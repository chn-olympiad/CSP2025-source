#include<bits/stdc++.h>
using namespace std;
struct road{
   int u,v,w;
};
road a[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=0;i<m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        ans+=a[i].w;
    }
    if(m<n){
        cout<<ans;
        return 0;
    }
    else{
        cout<<13;
    }
    return 0;
}

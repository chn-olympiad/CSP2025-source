#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
int ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
//    cout<<"I don't know!";
    cin>>n>>m>>k;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        ans+=w;
    }
    cout<<ans;
    return 0;
}

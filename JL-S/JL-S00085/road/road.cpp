#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,x,y,z;
int main(){
    freopen("road,in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        ans+=z;
    }
    for(int i=1;i<=k;i++){
        int fd;
        cin>>fd;
        int j;
        for(int s=1;s<=n;s++) cin>>j;
    }
    cout<<ans;
    return 0;
}
